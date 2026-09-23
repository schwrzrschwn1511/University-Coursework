const topics = {
    addition: {
        title: "Addition",
        text: "Addition is the process of finding the total, or sum, by combining two or more numbers. For example, 2 + 3 = 5.",
        video: "https://www.youtube.com/embed/qM7B2nwpV1M"
    },
    subtraction: {
        title: "Subtraction",
        text: "Subtraction is the process of finding the difference between two numbers. For example, 5 - 3 = 2.",
        video: "https://www.youtube.com/embed/rqiu_xcvSk4"
    },
    multiplication: {
        title: "Multiplication",
        text: "Multiplication is the process of finding the product by combining equal groups. For example, 2 x 3 = 6.",
        video: "https://www.youtube.com/embed/SRiYDszxruc"
    },
    division: {
        title: "Division",
        text: "Division is the process of splitting a number into equal parts. For example, 6 ÷ 3 = 2.",
        video: "https://www.youtube.com/embed/T3h1HUVHLJo"
    }
};

function showContent(topic) {
    const content = document.getElementById('content');
    content.style.display = 'block';

    const contentTitle = document.getElementById('content-title');
    const contentText = document.getElementById('content-text');
    const contentVideo = document.getElementById('content-video');

    contentTitle.textContent = topics[topic].title;
    contentText.textContent = topics[topic].text;
    contentVideo.src = topics[topic].video;
}
