const express = require("express");
const { dirname } = require("path");
const app = express();
const path = require('path');
app.use(express.static(__dirname+'inst.png'))
let request;
const { SerialPort } = require('serialport');
var bodyParser = require('body-parser');
app.use(bodyParser.urlencoded());
const arduino = new SerialPort({path:'COM3',baudRate: 9600})
app.get("/",function(req,res)
{
    res.sendFile(__dirname+"/index.html");
});
app.post('/',(req,res) =>
{
    request = req.body.note1;
    console.log(request);
    var texto = request;
    arduino.write(texto);
});
console.log("oi");
app.listen(8080,function(){console.log("Server rodando")});