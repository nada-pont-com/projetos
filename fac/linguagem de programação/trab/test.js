var doc = document.getElementsByTagName('body')[0];
console.log(doc)
// if(doc == 0)
doc.innerHTML = "<input id='num1' style='margin:10px'/><br><input id='num2'  style='margin:10px'><br><button onclick='calcula()'> calcula</button>";

function calcula() {
	num1 = document.getElementById("num1").value;
	num2 = document.getElementById("num2").value;

	mult = num1*num2;

	div = num1/num2;

	alert("mult = "+mult);
	alert("div = "+div);
}