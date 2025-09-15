const firstNumber = document.getElementById("fn");
const lastNumber = document.getElementById("ln");
const optionA = document.getElementById("opa");
const optionB = document.getElementById("opb");
const optionC = document.getElementById("opc");
const optionD = document.getElementById("opd");
var random;
var time = 5;

start(); //If you want the quiz to start as soon as the page loads
function start()
{
//Generating random numbers for FIrst number and Last number.
firstNumber.innerHTML = Math.floor(Math.random() * 10);
lastNumber.innerHTML = Math.floor(Math.random() * 10);
//Converting First number and Last Number into integer value from a string.
let x = parseInt(firstNumber.innerHTML);
let y = parseInt(lastNumber.innerHTML);
//Adding FIrst number and Last Number to get answer.
let answer = x + y;
console.log(answer);
//Generating random numbers from 0-20 for options.
var rd1 =Math.floor(Math.random() * 21);
var rd2 =Math.floor(Math.random() * 21);
var rd3 =Math.floor(Math.random() * 21);
var rd4 =Math.floor(Math.random() * 21);
//Filter: For two options being the same.
if (rd1 == answer)
{
    rd1++
}
if (rd2 == answer)
{
    rd2++;
}
if (rd3 == answer)
{
    rd3++;
}
if (rd4 == answer)
{
    rd4++;
}
//Assaigning values to options.
optionA.innerHTML = rd1;
optionB.innerHTML = rd2;
optionC.innerHTML = rd3;
optionD.innerHTML = rd4;
//randomly selecting a correct answer.
let list = [optionA, optionB, optionC, optionD]
random = Math.floor(Math.random() * 4);
list[random].innerHTML = answer;
}



function chek(x) {
    console.log(random)
    if (x == random) 
    {
        console.log("correct");
        
        document.getElementById("correct").innerHTML +++ 1;
        start();
    }else 
    {
        console.log("incorrect")
        
        document.getElementById("incorrect").innerHTML +++ 1;
        start();
    }
 
}
