const AQICN_API_KEY = 'AQINCN_API';
const LEAFLET_API_KEY = 'LEAFLET_API_KEY';

document.getElementById('search-btn').addEventListener('click', () => {
    const cityName = document.getElementById('city-input').value;
    if (cityName) {
        getAQI(cityName);
    }
});

async function getAQI(city) {
    try {
        const response = await fetch(`https://api.waqi.info/feed/${city}/?token=${AQICN_API_KEY}`);
        const data = await response.json();
        if (data.status === 'ok') {
            updateUI(data.data);
        } else {
            alert('City not found or error in fetching data');
        }
    } catch (error) {
        console.error('Error fetching AQI data:', error);
    }
}

let map; 
let marker; 

function initMap() {
    
    map = L.map('map').setView([0, 0], 2);

    
    L.tileLayer(`https://api.mapbox.com/styles/v1/{id}/tiles/{z}/{x}/{y}?access_token=${LEAFLET_API_KEY}`, {
        maxZoom: 18,
        id: 'mapbox/streets-v11',
        tileSize: 512,
        zoomOffset: -1,
        accessToken: LEAFLET_API_KEY,
    }).addTo(map);

    marker = L.marker([0, 0]).addTo(map);
}

function updateUI(data) {
    let quality;
    let imgUrl;
    
    if (data.aqi <= 50) {
        quality = "Good";
        imgUrl = "img/good.png";
    } else if (data.aqi > 50 && data.aqi <= 100) {
        quality = "Moderate";
        imgUrl = "img/moderate.png";
    } else if (data.aqi > 100 && data.aqi <= 150) {
        quality = "Unhealthy for Sensitive Groups";
        imgUrl = "img/unhealthy for sensitive.png";
    } else if (data.aqi > 150 && data.aqi <= 200) {
        quality = "Unhealthy";
        imgUrl = "img/unhealthy.png";
    } else if (data.aqi > 200 && data.aqi <= 300) {
        quality = "Very Unhealthy";
        imgUrl = "img/very unhealthy.png";
    } else if (data.aqi > 300) {
        quality = "Hazardous";
        imgUrl = "img/hazardous.png";
    }
    else if(data.aqi = "-"){
        quality = "Undefined";
        imgUrl = "img/undefined.png";
    }
        

    document.getElementById('city-name').textContent = `City: ${data.city.name}`;
    
  
    const aqiValueElement = document.getElementById('aqi-value');
    aqiValueElement.innerHTML = `AQI: ${data.aqi} <img src="${imgUrl}" width="60" height="60" alt="${quality}">`;

    map.setView(data.city.geo, 11);
    marker.setLatLng(data.city.geo);
}

initMap();
