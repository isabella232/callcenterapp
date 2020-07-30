#### Have you ever wanted to get data from a form, process this data, and then use this data for your own use? Data analysis is a crucial step in many businesses, and fortunately we can use a simple Azure logic app and some HTML code to achieve complex refinement of masses of form data. 

Here’s a brief visual overview of the components of our project:

![Flowchart](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/1.png)

Part 1 of this tutorial focuses on the HTML Webform and Azure Storage Blob, while Part 2 discusses Azure Logic Apps and the Outlook API. The tutorial closes by suggesting possible add-ons. 

You are looking at Part 1 of this tutorial. 

The first thing we want to do is to create the working directory where our code will go. Open your text editor or folder system and create a new folder. Name this folder “CallCenterProject Directory”. 
 
![Flowchart](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/2.png)
 
Your folder should look something like this:

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/3.png)
 
Right now, your folder is empty, but we will be putting our html code in this directory.
After you have created your folder, open it as a directory from within your text editor. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/4.png)

You should be prompted to choose a working directory. Select the folder you just created, “CallCenterProject Directory” and click “Open”. 
At this stage, you should be seeing something similar to the following

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/5.png)
 
Now it’s time to create the html webform to get the data. 
In your text editor, create a new file. Name it as index.html.

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/6.png)
 
Enter the html code for your webform on this page. Sample html code has been provided below. Feel free to customize the code to your needs. Citation to Bit Project at the top of your code would be appreciated. 
````HTML
<!DOCTYPE html>
<html lang="en">
<head>
  <link rel="stylesheet" href="style.css">

  <title> BITHERO CALL CENTER </title>
  <script src="https://kit.fontawesome.com/a076d05399.js"></script>
</head>
<body>
   <i class="fas fa-bars"></i>

    <H1>BITHERO CALL CENTER</H1>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/dropzone/5.1.1/min/dropzone.min.css" crossorigin="anonymous">

    <style>
        html {
            font-family: 'Trebuchet MS', 'Lucida Sans Unicode', 'Lucida Grande', 'Lucida Sans', Arial, sans-serif;
        }

        main {
            margin: 20px;
        }

        #gallery-note {
            font-size: smaller
        }

        .dropzone {
            border: 3px dashed #00a1f1;
            background: #F0F8FF;
            margin: 25px;
            border-radius: 5px;
            max-width: 1000px;
        }

        .dropzone .dz-message {
            font-weight: 300;
        }

        .dropzone .dz-message .note {
            font-family: sans-serif;
            font-size: 18px;
            font-weight: 200;
            display: block;
            margin-top: 1.5rem;
        }
    </style>

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/dropzone/5.1.1/min/dropzone.min.js"></script>
    <form id = "submitMessage" method="post" class = "dropzone">
          <h4>Enter your call statistics here.</h4>
        <ul>
            <li>
                <label for="blocked">Was this call blocked due to a busy tone?</label>
                <select id="blocked" name="blocked">
                    <option value="No">No</option>
                    <option value="Yes">Yes</option>
                </select>
            </li>
            <li>
                <label for="abandoned">Was this call abandoned by the customer?</label>
                <select id="abandoned" name="abandoned">
                    <option value="No">No</option>
                    <option value="Yes">Yes</option>
                </select>
            </li>
            <li>
                <label for="waitingtime">What was the time (in minutes) the customer spent in the waiting queue?</label>
                <input type="text" id="waitingtime" name="customer_waitingtime">
            </li>
            <li>
                <label for="problemarea">What was the problem area?</label>
                <select id="problemarea" name="problemarea">
                    <option value="Problem 1">Problem 1</option>
                    <option value="Problem 2">Problem 2</option>
                    <option value="Problem 3">Problem 3</option>
                    <option value="Problem 4">Problem 4</option>
                    <option value="Problem 5">Other</option>
                </select>
            </li>
            <li>
                <label for="issueresolved">Was the issue resolved?</label>
                <select id="issueresolved" name="issueresolved">
                    <option value="Yes">Yes</option>
                    <option value="No">No</option>
                </select>
            </li>
            <li>
                <label for="resolvetime">How long (in minutes) did it take to solve the problem?</label>
                <input type="text" id="resolvetime" name="resolve_time">
            </li>
            <li>
                <label for="calltime">How long did the call last?</label>
                <input type="text" id="calltime" name="calltime">
            </li>
            <li>
                <label for="aftercallwork">How much time was spent on after-call work?</label>
                <input type="text" id="aftercallwork" name="aftercallwork">
            </li>
            <!--  <li class="button">
                <button type="submit">Continue to the next portion.</button>
            </li>-->
        </ul>
    <h4>Enter your identification info here.</h4>
        <ul>
            <div class="container">
                <div class="row">
                    <div class="col-25">
                        <label for="Name">Last Name</label>
                    </div>
                    <div class="col-75">
                        <input type="text" id="lname" name="lastname" placeholder="Your last name..">
                    </div>
                </div>
                <div class="row">
                    <div class="col-25">
                        <label for="country">Call Center</label>
                    </div>
                    <div class="col-75">
                        <select id="country" name="country">
                            <option value="1">CallCenter 1</option>
                            <option value="2">CallCenter 2</option>
                            <option value="3">CallCenter 3</option>
                            <option value="4">CallCenter 4</option>
                            <option value="other">Other</option>
                        </select>
                    </div>
                </div>
                <div class="row">
                    <div class="col-25">
                        <label for="subject">Comment</label>
                    </div>
                    <div class="col-75">
                        <textarea id="subject" name="Comment" placeholder="Write something.." style="height:200px"></textarea>
                    </div>
                </div>
                <div class="row">
                    <input type="submit" value="Submit Identifier Info and Call Statistics.">
                </div>
                </div>
                </ul>
    </form>
    <h5>© Shreyan 2020 </h5>
  <script>
  submitMessage.onsubmit = async (e) => {
    e.preventDefault();

    let response = await fetch('<Your link>', {
      method: 'POST',
      body: new FormData(submitMessage)
    });

    let result = await response.json();

    alert(result.message);
  };

</script>
</body>

</html>
````
Create another file in your text editor and name it style.css. Enter the following styling information on that page:
```` CSS
body {
  background-color: whitesmoke;
  color: black;
  font: courier
}


img {
  border-radius: 23px;
  float: center;
  border-width: 100px;
}

/* Style the header with a grey background and some padding */
.header {
  overflow: hidden;
  background-color: black;
  padding: 20px 10px;
}

/* Style the header links */
.header a {
  float: left;
  color: white;
  text-align: center;
  padding: 12px;
  text-decoration: none;
  font-size: 18px;
  line-height: 25px;
  border-radius: 4px;
  font-weight: bold;
  font-family: monospace
}

/* Style the logo link (notice that we set the same value of line-height and font-size to prevent the header to increase when the font gets bigger */
.header a.logo {
  font-size: 25px;
  font-weight: bold;
}

/* Change the background color on mouse-over */
.header a:hover {
  background-color: #ddd;
  color: white;
}

/* Style the active/current link*/
.header a.active {
  background-color: dodgerblue;
  color: white;
  font-family: cursive
}

/* Float the link section to the right */
.header-right {
  float: right;
}

/* Add media queries for responsiveness - when the screen is 500px wide or less, stack the links on top of each other */
@media screen and (max-width: 500px) {
  .header a {
    float: none;
    display: block;
    text-align: left;
  }

  .header-right {
    float: none;
  }
}


footer {
  overflow: hidden;
  background-color: black;
  padding: 20px 10px;
}


/* Bordered form */
form {
  border: 3px solid #f1f1f1;
}

/* Full-width inputs */
input[type=text], input[type=password] {
  width: 100%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  box-sizing: border-box;
}

/* Set a style for all buttons */
button {
  background-color: #4CAF50;
  color: white;
  padding: 14px 20px;
  margin: 8px 0;
  border: none;
  cursor: pointer;
  width: 100%;
}

/* Add a hover effect for buttons */
button:hover {
  opacity: 0.8;
}

/* Extra style for the cancel button (red) */
.cancelbtn {
  width: auto;
  padding: 10px 18px;
  background-color: #f44336;
}

/* Center the avatar image inside this container */
.imgcontainer {
  text-align: center;
  margin: 24px 0 12px 0;
}

/* Avatar image */
img.avatar {
  width: 15%;
  border-radius: 16.667%;
}

/* Add padding to containers */
.container {
  padding: 16px;
}

/* The "Forgot password" text */
span.psw {
  float: right;
  padding-top: 16px;
}

/* Change styles for span and cancel button on extra small screens */
@media screen and (max-width: 300px) {
  span.psw {
    display: block;
    float: none;
  }

  .cancelbtn {
    width: 100%;
  }
}

/* The Modal (background) */
.modal {
  display: none;
  /* Hidden by default */
  position: fixed;
  /* Stay in place */
  z-index: 1;
  /* Sit on top */
  left: 0;
  top: 0;
  width: 100%;
  /* Full width */
  height: 100%;
  /* Full height */
  overflow: auto;
  /* Enable scroll if needed */
  background-color: rgb(0, 0, 0);
  /* Fallback color */
  background-color: rgba(0, 0, 0, 0.4);
  /* Black w/ opacity */
  padding-top: 60px;
}

/* Modal Content/Box */
.modal-content {
  background-color: #fefefe;
  margin: 5px auto;
  /* 15% from the top and centered */
  border: 1px solid #888;
  width: 80%;
  /* Could be more or less, depending on screen size */
}

/* The Close Button */
.close {
  /* Position it in the top right corner outside of the modal */
  position: absolute;
  right: 25px;
  top: 0;
  color: #000;
  font-size: 35px;
  font-weight: bold;
}

/* Close button on hover */
.close:hover,
.close:focus {
  color: red;
  cursor: pointer;
}

/* Position the image container (needed to position the left and right arrows) */
.container {
  position: relative;
}

/* Hide the images by default */
.mySlides {
  display: none;
}

/* Add a pointer when hovering over the thumbnail images */
.cursor {
  cursor: pointer;
}



/* Style inputs, select elements and textareas */
input[type=text], select, textarea{
  width: 100%;
  padding: 12px;
  border: 1px solid #ccc;
  border-radius: 4px;
  box-sizing: border-box;
  resize: vertical;
}

/* Style the label to display next to the inputs */
label {
  padding: 12px 12px 12px 0;
  display: inline-block;
}

/* Style the submit button */
input[type=submit] {
  background-color: #4CAF50;
  color: white;
  padding: 12px 20px;
  border: none;
  border-radius: 4px;
  cursor: pointer;
  float: right;
}

/* Style the container */
.container {
  border-radius: 5px;
  background-color: #f2f2f2;
  padding: 20px;
  border-color:#4CAF50;
}

/* Floating column for labels: 25% width */
.col-25 {
  float: left;
  width: 25%;
  margin-top: 6px;
}

/* Floating column for inputs: 75% width */
.col-75 {
  float: left;
  width: 75%;
  margin-top: 6px;
}

/* Clear floats after the columns */
.row:after {
  content: "";
  display: table;
  clear: both;
}

/* Responsive layout - when the screen is less than 600px wide, make the two columns stack on top of each other instead of next to each other */
@media screen and (max-width: 600px) {
  .col-25, .col-75, input[type=submit] {
    width: 100%;
    margin-top: 0;
  }
}

table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

td, th {
  border: 1px solid #dddddd;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
  background-color: #dddddd;
}

dd{
  position: relative;
  font-family: sans-serif;
  text-transform: uppercase;
  font-size: 1em;
  letter-spacing: 4px;
  overflow: hidden;
  background: linear-gradient(90deg, #000, #fff, #000);
  background-repeat: no-repeat;
  background-size: 80%;
  animation: animate 3s linear infinite;
  -webkit-background-clip: text;
  -webkit-text-fill-color: rgba(255, 255, 255, 0);
}

dl{
  margin-left:5%;
}
````

This is what you should see now:

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/7.png)
 
Open your HTML file on your web browser to make sure you like how your web form looks. 
Using the suggested html and css, the webpage looks like the following:

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/8.png)
 
You can always change the form fields and the format as you see fit. 

Try filling out the form and clicking the “Submit” button. Since the website is not hosted by any server, nothing will happen after you fill out the form yet. 

The next step is to host this website using Azure and send the form data as a text file in json format to Blob Storage. 

Begin by navigating to the Azure Portal. Search for Logic Apps on the top menu, and select it. If you don’t see it, click “Create a Resource”. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/9.png)

Search for “Logic App”. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/10.png)

Azure Logic Apps should be the first option that comes up. Click on it, and you will be directed to the following page:
 
![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/11.png)

Click “Create”. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/12.png)
 
Before you can fully deploy your Azure Logic App, you need to specify your subscription, resource group, and location. The resource group is the directory in which your project will be in. Fill out all of the information accordingly, and then click “Review + Create”. 
Make sure you fill out all the required information (demarcated by a red asterisk) before you proceed. After you do so, you will be redirected to a page that looks like the following:

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/13.png)

The page details some starters and templates you can use. For the purpose of this project, scroll down and select “Blank Logic App”. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/14.png)
 
Then, navigate to the main page of your logic app. The top menu should look as follows. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/15.png)
 
Click “Edit”. You will be directed to the logic apps designer. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/16.png)
 
Right now, you don’t have any blocks in the designer. To get started, click on “Code View” in the top menu. You should see some code already put there for you. 
Navigate back to the Azure Portal. Click “Create a Resource” again. This time, search up “Storage account”. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/17.png)
 
 Click “Create” and again fill out the necessary information. You would want your storage account to be in the same directory as your logic app. Your storage account needs to be V2 (default). 
After creating your storage account, go to it and you will see the following:

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/18.png)
 
Click “Containers” and add one. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/19.png)
 
Name it as you see fit, and make it private. 

After you’ve created the container, open it up and upload the index.html and css files by clicking the upload icon on the top menu. 

Go to the left navigation bar and search for “Static Website”.  Enable it if it hasn’t been already, and copy the link. 

Create a new container. In this container, you will send your form data. 

Now, go back to your logic app. Use the following blocks in the order provided. The blocks have been renamed for documentation purposes. When prompted, search for the block in the menu, and click the appropriate option. More details on what to put inside the blocks will be provided later. 

<p align = "center">
![Flowchart](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/20.png)
![Flowchart](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/21.png)
![Flowchart](https://github.com/11301858/callcenterapp/blob/master/tutorial/p2images/22.png)
</p>
 
We will fill these blocks with code in the next part. 
