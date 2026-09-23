const questions = [
    // Addition
    {
        topic: "Addition",
        question: "What is 5 + 3?",
        options: ["5", "7", "8", "10"],
        answer: "8"
    },
    {
        topic: "Addition",
        question: "What is 10 + 4?",
        options: ["12", "14", "15", "16"],
        answer: "14"
    },
    {
        topic: "Addition",
        question: "What is 7 + 2?",
        options: ["8", "9", "10", "11"],
        answer: "9"
    },
    {
        topic: "Addition",
        question: "What is 1 + 6?",
        options: ["5", "6", "7", "8"],
        answer: "7"
    },
    {
        topic: "Addition",
        question: "What is 9 + 3?",
        options: ["10", "11", "12", "13"],
        answer: "12"
    },
    // Subtraction
    {
        topic: "Subtraction",
        question: "What is 10 - 4?",
        options: ["5", "6", "7", "8"],
        answer: "6"
    },
    {
        topic: "Subtraction",
        question: "What is 15 - 9?",
        options: ["5", "6", "7", "8"],
        answer: "6"
    },
    {
        topic: "Subtraction",
        question: "What is 8 - 3?",
        options: ["4", "5", "6", "7"],
        answer: "5"
    },
    {
        topic: "Subtraction",
        question: "What is 12 - 8?",
        options: ["3", "4", "5", "6"],
        answer: "4"
    },
    {
        topic: "Subtraction",
        question: "What is 9 - 5?",
        options: ["3", "4", "5", "6"],
        answer: "4"
    },
    // Multiplication
    {
        topic: "Multiplication",
        question: "What is 3 * 3?",
        options: ["6", "8", "9", "12"],
        answer: "9"
    },
    {
        topic: "Multiplication",
        question: "What is 4 * 2?",
        options: ["6", "7", "8", "9"],
        answer: "8"
    },
    {
        topic: "Multiplication",
        question: "What is 5 * 5?",
        options: ["20", "25", "30", "35"],
        answer: "25"
    },
    {
        topic: "Multiplication",
        question: "What is 6 * 3?",
        options: ["16", "18", "20", "22"],
        answer: "18"
    },
    {
        topic: "Multiplication",
        question: "What is 7 * 2?",
        options: ["12", "14", "16", "18"],
        answer: "14"
    },
    // Division
    {
        topic: "Division",
        question: "What is 12 / 4?",
        options: ["2", "3", "4", "6"],
        answer: "3"
    },
    {
        topic: "Division",
        question: "What is 15 / 3?",
        options: ["4", "5", "6", "7"],
        answer: "5"
    },
    {
        topic: "Division",
        question: "What is 9 / 3?",
        options: ["2", "3", "4", "5"],
        answer: "3"
    },
    {
        topic: "Division",
        question: "What is 16 / 4?",
        options: ["3", "4", "5", "6"],
        answer: "4"
    },
    {
        topic: "Division",
        question: "What is 18 / 6?",
        options: ["2", "3", "4", "5"],
        answer: "3"
    }
];

let currentQuestionIndex = 0;
let score = 0;
let totalQuestions = questions.length;
let userName = '';
let userId = '';

function showUserForm() {
    document.querySelector('.home').style.display = 'none';
    document.getElementById('user-form').style.display = 'flex';
}

function startQuiz() {
    userName = document.getElementById('user-name').value;
    userId = document.getElementById('user-id').value;
    if (userName === '' || userId === '') {
        alert('Please enter your name and ID.');
        return;
    }
    document.getElementById('user-form').style.display = 'none';
    document.getElementById('quiz-section').style.display = 'flex';
    showQuestion();
}

function showQuestion() {
    let questionText = document.getElementById('question-text');
    let optionList = document.getElementById('option-list');
    let questionNumber = document.getElementById('question-number');
    let questionTotal = document.getElementById('question-total');
    let topicHeader = document.getElementById('topic-header');

    let question = questions[currentQuestionIndex];
    questionText.innerText = question.question;
    topicHeader.innerText = question.topic;

    optionList.innerHTML = '';
    question.options.forEach(option => {
        let optionElement = document.createElement('div');
        optionElement.className = 'option';
        optionElement.innerText = option;
        optionElement.onclick = () => selectOption(optionElement, question.answer);
        optionList.appendChild(optionElement);
    });

    questionNumber.innerText = `Question ${currentQuestionIndex + 1}`;
    questionTotal.innerText = `Total: ${currentQuestionIndex + 1}/${totalQuestions}`;
    document.getElementById('next-btn').classList.remove('active');
}

function selectOption(optionElement, correctAnswer) {
    let options = document.querySelectorAll('.option');
    options.forEach(option => option.classList.add('disabled'));

    if (optionElement.innerText === correctAnswer) {
        optionElement.classList.add('correct');
        score++;
    } else {
        optionElement.classList.add('incorrect');
        options.forEach(option => {
            if (option.innerText === correctAnswer) {
                option.classList.add('correct');
            }
        });
    }

    document.getElementById('next-btn').classList.add('active');
}

function nextQuestion() {
    if (!document.querySelector('.option.correct') && !document.querySelector('.option.incorrect')) {
        alert("Please select an answer before proceeding.");
        return;
    }

    currentQuestionIndex++;
    if (currentQuestionIndex < totalQuestions) {
        showQuestion();
    } else {
        showResult();
    }
}

function showResult() {
    let scorePercentage = Math.round((score / totalQuestions) * 100);
    saveResult(userName, userId, scorePercentage);
    document.querySelector('.quiz-box').innerHTML = `
        <div class="quiz-header">
            <span id="question-number">Results</span>
            <span id="header-score">Score: ${scorePercentage}%</span>
        </div>
        <div class="result-box active">
            <div class="circular-progress">
                <div class="progress-value" id="progress-value">${scorePercentage}%</div>
            </div>
            <div class="score-text">You scored ${scorePercentage}%</div>
            <div class="buttons">
                <button onclick="retakeQuiz()">Retake Quiz</button>
            </div>
        </div>
    `;
}

function retakeQuiz() {
    currentQuestionIndex = 0;
    score = 0;
    document.getElementById('quiz-section').innerHTML = `
        <div class="quiz-box">
            <div class="quiz-header">
                <span id="question-number">Question 1</span>
                <span id="header-score">Score: 0%</span>
            </div>
            <div id="topic-header" class="topic-header"></div>
            <div class="question-text" id="question-text"></div>
            <div class="option-list" id="option-list"></div>
            <div class="quiz-footer">
                <span id="question-total">Total: 0/0</span>
                <button class="next-btn" id="next-btn" onclick="nextQuestion()">Next</button>
            </div>
        </div>
    `;
    showQuestion();
}

function saveResult(name, id, score) {
    fetch('save_result.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ name, id, score })
    });
}
