/* Junyan Chen
   jchen52@uoguelph.ca
   Computer Science CIS*1500
   Assignment 3 Question 2
*/

#include <stdio.h>
#include <string.h>

#define MAX_TWEET_LENGTH 60

int isValidTweet(char []);

int isTweetAReply(char []);

void shortTweet(char [], char [], char []);

int numTweetsRequired(char []);


//isValidTweet
int isValidTweet(char tweet[]){
 
  int answer = 0;  

    //checking if tweet is bigger than the MAX_TWEET_LENGTH (60) or smaller than the MAX_TWEET_LENGTH (60)
    if ((strlen(tweet) <= MAX_TWEET_LENGTH) && (strlen(tweet)>= 1)){          
      
      answer = 1;                       // It returns to 1 if it is between 60 and 1 characters
    }else{
     
      answer = 0;                       //It returns to 0 if it is bigger than 60 or less than 1 characters
    }
    
  return answer;
}

//isTweetAReply
int isTweetAReply(char tweet[]){

  int answer = 0;
  
    //checking if the user tweet is a return tweet.
    if (tweet[0] == '@'){
    
      answer = 1;           //If it found '@' in the first character then it is return tweet, and returns 1
    }else{
    
      answer = 0;           //If it didn't found '@' in the first character then it is not a return tweet, returns 0
    }
  
  return answer;
}

//shortTweet
void shortTweet(char tweet1[], char tweet2[], char result[]){
 
  //checking which tweet is shorter and if they are the same length
  if (strlen(tweet1) < strlen(tweet2)){
  
    strcpy(result, "Tweet 1");        //it returns Tweet 1 if the first tweet is short than the tweet 2
  }else if (strlen(tweet1) > strlen(tweet2)){
    
    strcpy(result, "Tweet 2");      //it returns Tweet 2 if the second tweet is short than the tweet 1
  }else if (strlen(tweet1) == strlen(tweet2)){
    
    strcpy(result, "Same Length");  // it returns Same Length if the both strings are the same size
  }

return;
}

//numTweetsRequired
int numTweetsRequired(char tweet[]){

  int tweetBox = 0;
    
    //checking how many tweets does user have and how many tweet boxes are required 
    
    if (strlen(tweet) > MAX_TWEET_LENGTH){  //if the tweet is longer than 60 it you take you into another if statement
      
      //check if the tweet length of the tweet divide by 60 has a reaminder of 0 or not.
      if (strlen(tweet) % MAX_TWEET_LENGTH == 0){
        
        tweetBox = strlen(tweet) / MAX_TWEET_LENGTH;  //It will return the exact number of tweet box if the tweet the reaminder is 0.
        
      }else{  //if the remainder is not 0, that means it will need another text to hold the rest of the text
          
        tweetBox = (strlen(tweet) / MAX_TWEET_LENGTH) + 1; //it will add one extra tweet box for the remainder of the text
      }
    
    }else{
      
      // if the tweet is less than 60, it will just use one tweet box 
      tweetBox = 1;
    }
    
  return tweetBox;
}

