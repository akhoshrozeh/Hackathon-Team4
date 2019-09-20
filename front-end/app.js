// Sets console.log() to print to Evothings console
if (window.hyper && window.hyper.log) { console.log = hyper.log }
 
document.addEventListener(
    'deviceready',
    function() {
    /*TODO: Add your callback here*/
        app.initialize();
});
 
var app = {} //establishing app as a new object, object creation
 
app.SERVICE_UUID='0000ffe0-0000-1000-8000-00805f9b34fb'; //the service UUID for our bluetooth
app.CHARACTERISTIC_UUID='0000ffe1-0000-1000-8000-00805f9b34fb'; //the Characteristic UUID for our bluetooth
 
app.showControls = function() //shows our controls menu for
{
    $('#disconnect').prop('disabled', false);
    $('#startView').hide();
    $('#controlsView').show();
}
 
app.showStart = function()
{
    $('#disconnect').prop('disabled', true);
    $('#startView').show();
    $('#controlsView').hide();
}
 
app.initialize = function() //handles intializing our device
{
        console.log('Initialized'); //console logs the following prompt Initialized
        app.connected = false; //setting our app.connected as a boolean variable, setting it to false
        app.device = null; //currently app.device isnt getting our bluetooth device.
}
 
    app.connect = function() //create our app.connect function, connects our device
    {
        console.log('Attempting to connect to bluetooth module') //console logs that we are attempting to connect to bluetooth
 
        evothings.easyble.startScan(scanSuccess, scanFailure, {SERVICE_UUIDS:  [app.SERVICE_UUID]}, {allowDuplicates: false});
        //evothings specific command, we call scanSuccess,ScanFailure, and our bluetooth UUID. No duplicates
        //evothings specific command, startScan, starts scanning for devices
    }
 
function scanSuccess(device)
{
    if(device.address == '29CC2845-E4AD-CD62-BAC3-C5C4E4E1F63D') //if our bluetooth name has been established...
    {
        console.log('Found' + device.name); //print in the console "Found (device name)"
        device.connect(connectSuccess, connectFailure); //accessing the connect variable in object device, checking connectSuccess and connectFailure
                                                        //device.connect is evothings specific and used to connect to the device
        evothings.easyble.stopScan(); //evothings specific command, stopScan, stops scanning for devices.
    }
}
//git merge
 
function scanFailure(errorCode)
{
    console.log(Error + errorCode); //print in the console an errorcode
}
 
function connectSuccess(device)
{
    console.log('Successfully connected!!'); //print to console successfully connected
    app.connected = true; //set app.connected to true, this function is called when connectSuccess is called
    app.device = device; //set app.device to this device
    app.device.readServices(serviceSuccess, serviceFailure, [app.SERVICE_UUID]) //Read services,
    //characteristics and descriptors for app.SERVICE_UUID. We will call this before reading and
    //writing characteristics/descriptors
}
 
function connectFailure()
{
    app.connected = false; //set app.connected to false, our connection was a failure.
    console.log('Failed to connect'); //print out failed to connect
}
 
app.disconnect = function(errorMessage)
{
    if(errorMessage) //if errormessage
    {
        console.log(errorMessage); //in console print the error message
    }
    app.connected = false; //set the app.connected to false, disconnect the app.
    app.device = null; //app.device no longer gets the device and is set to null again
 
    evothings.easyble.stopScan(); //stop scanning devices
    evothings.easyble.closeConnectedDevices(); //close any connected devices
}
 
function serviceSuccess(device)
{
    console.log('The bluetooth module can now read and write');
    app.device.enableNotification(
        app.SERVICE_UUID,
        app.CHARACTERISTIC_UUID,
        app.recievedData,
        function(errorCode)
        {
            console.log('Failed to receive notification from device' + errorCode);
        },
        {writeConfigDescriptor: false}
    );
}
 
function serviceFailure(errorCode)
{
    console.log('Failed to read services' + errorCode);
    app.disconnect();
}
app.sendData = function(data)
{
    if (app.connected && app.device != null)
    {
        data = new Uint8Array(data); //8bit array
        app.device.writeCharacteristic( //specific to evothings, works with codoba devices
        app.CHARACTERISTIC_UUID,
        data,
        function ()
        {
            console.log('Succeeded to send message!' + data);
        }, //this small function is considered a parameter
        function (errorCode)
        {
            console.log('Failed to send message!' + errorCode);
        }, //small function, considered a paramter, logs the errorCode
    );
    }
    else
    {
        app.disconnect('Device was disconnected when trying to send message');
    }
}
 
app.recievedData() = function(data)
{
    //0X10
    if (data == 0x16)
    {
        //vibrate the phone, change the color of button, ...
    }
}
