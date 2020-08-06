## Doing Sentiment Analysis on Call Center Agent Comments Submitted Through Webform

In Part 3 of our tutorial we mentioned sentiment analysis of call center agent comments as a possible add-on. This document will guide you through how to do that. 
Go to Azure Marketplace (found on the top navigation bar of your portal). If you need help on how to navigate Azure, refer to the previous parts of the tutorial. 

Search for "Text Analytics". Text Analytics is a part of Azure Cognitive Services, and it will help us analyze sentiment and extract key phrases from any comments left on your webform. 
After creating a new text analytics resource under your subscription and resource group, retrieve the keys from the page you are redirected to. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/addonimages/32.png)

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/addonimages/33.PNG)

Go to your logic app and use this key to add a text analytics connector. As your text to analyze put the array containing the specific webform data you want to examine. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/addonimages/34.PNG)

Parse the output of your text analysis as a json file and then use this data in your weekly report email. 

![](https://github.com/11301858/callcenterapp/blob/master/tutorial/addonimages/35.PNG)
