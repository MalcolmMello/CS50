const checkAnswer = document.querySelector('#check');
const buttons = document.querySelectorAll('#option');
const answer = document.querySelector('.answer');
const answerInput = document.querySelector('.answerInput');

let currentAnswer = 0;

buttons.forEach(item => {
    item.addEventListener('click', () => {
        if(currentAnswer !== 0)
        {
            resetStyles(buttons[currentAnswer - 1]);
        }

        currentAnswer = Number(item.accessKey);

        item.accessKey === "4" ? addStyles("green", "Correto!", item, answer) : addStyles("red", "Errado!", item, answer);
    });
});

checkAnswer.addEventListener('click', () => {
    let input = document.querySelector('input');
    let inputValue = input.value.trim();

    if(inputValue.length > 0)
    {
        inputValue === "Argentina" ? addStyles("green", "Correto!", input, answerInput) : addStyles("red", "Errado!", input, answerInput);
    } else
    {
        alert("Digite sua resposta!!");
    }
});

function addStyles(color, text, item, answer)
{
    item.style.backgroundColor = color;
    answer.style.color = color;
    answer.textContent = text;
}

function resetStyles(item)
{
    item.style.backgroundColor = "#d9edff";
    item.style.color = "#000000";
    answer.textContent = "";
}