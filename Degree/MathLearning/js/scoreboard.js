document.addEventListener('DOMContentLoaded', () => {
    fetch('get_scores.php')
        .then(response => response.json())
        .then(data => {
            const tbody = document.querySelector('#scoreboard-table tbody');
            data.forEach(row => {
                const tr = document.createElement('tr');
                tr.innerHTML = `
                    <td>${row.name}</td>
                    <td>${row.user_id}</td>
                    <td>${row.score}%</td>
                    <td>${row.reg_date}</td>
                `;
                tbody.appendChild(tr);
            });
        });
});
