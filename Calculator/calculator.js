let number = '';
let result = 0;
let input = 0;
let character = '';
function clickButton(userInput){
   
    if(userInput === '1'){
       number = number + userInput; 
    }
    
    else if(userInput === '2'){
        number = number + userInput;
    
    }
    else if(userInput === '3'){
        number = number + userInput;
      
    }
    else if(userInput === '4'){
        number = number + userInput;
      
    }
    else if(userInput === '5'){
        number = number + userInput;
       
    }
    else if(userInput === '6'){
        number = number + userInput;
        
    }
    else if(userInput === '7'){
        number = number + userInput;
       
    }
    else if(userInput === '8'){
        number = number + userInput;
       
    }
    else if(userInput === '9'){
        number = number + userInput;
       
    }
    else if(userInput === '0'){
        number = number + userInput;
      
    }
    else if(userInput === '.'){
        number = number + userInput;
      
    }
    else if(userInput === '+'){
        calculate(userInput);
        character = '+';
        number = '';
    }
    else if(userInput === '-'){
        calculate(userInput);
        character = '-';
        number = '';
    }
    else if(userInput === '*'){
        calculate(userInput);
        character = '*';
        number = '';
    }
    else if(userInput === '/'){
        calculate(userInput);
        character = '/';
        number = '';
    }
    else if(userInput === '='){
        equalSign();
        number = '';
    }
    input = Number(number);
}
   
 
function calculate(userInput){
    if(userInput === '+'){
        if(input === 0 && result ===0){
            number = number + '+';
        }
        else{
            result = result + input;
        }
    }
   else if(userInput === '-'){
        if(input === 0 && result === 0) {
            number = number + '-';
        }
        else if(result === 0){
            result = input;
        }
        else{
            result = result - input;
           
        }
    }
    else if(userInput === '*'){
        if(input === 0 && result ===0){
           document.querySelector('.unexpected-input').innerHTML = 'unexpected-input';
        }
        else if(result === 0){
            result = input;
        } 
        else if(input === 0){
            
        }
        else{
            result = result * input;
        }    
    }
    else if(userInput === '/'){
        if(input === 0 && result === 0){
           document.querySelector('.unexpected-input').innerHTML = 'unexpected-input';
        }
        else if(result === 0){
            result = input;
        }
        else if(input === 0) {
            document.querySelector('input-and-result').innerHTML = 'infinity';
        }
        else{
            result = result / input;
        }
    }
    input = 0;
}

function equalSign(){
    if(character === '+'){
        result = result + input;
    }
    else if(character === '-'){
            result = result - input;
    }
    else if(character === '*'){
        result = result * input;
    }
    else if(character === '/'){
        result = result / input;
    }
    input = 0;
   console.log("the result is: " + result);
   document.querySelector('.input-and-result').innerHTML = result;
   inputUserElement = result;
}
function clearAll(){
    result = 0;
    number = '';
    character = '';
    input = 0;
    console.log("the result is: " + result);
    document.querySelector('.input-and-result').innerHTML = '';
    inputUserElement = '';
    document.querySelector('.unexpected-input').innerHTML = '';
}
let inputUserElement = '';
function inputElement(inputFromUser){
    inputUserElement += inputFromUser;
    document.querySelector('.input-and-result').innerHTML = inputUserElement;
}