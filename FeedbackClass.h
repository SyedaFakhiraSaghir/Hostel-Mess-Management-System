#ifndef FeedbackClass
#define FeedbackClass

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#define size 10
class Feedback
{
protected:
	int id;
	string good_feedback[size] = { "We're so glad you enjoyed your meal! We look forward to seeing you again soon.","Thank you for your kind words! We strive to provide excellent service and delicious food.","We're hrilled to hear that you found your dish flavorful. We put a lot of care into our recipes.","We're gla to have met your expectations on the meal and presentation. Thank you for dining with us.","e're glad you enjoyed our restaurant's atmosphere and food. We hope to see you again soon","Thank you for your feedback! Our chef works hard to create unique and delicious dishes.","We're happy to hear that youfelt our portion size and pricing were reasonable. We aim to provide value for our guests","We're thrilled to hear that you finished every last bite! Thank you for dining with us.","Thank you for oticing the quality of our ingredients and the attention to detail we put into our dishes.","We're glad to have exceedd your expectations! We strive to provide our guests with an exceptional dining experience."    };
	string mod_feedback[size] = { "Thank you for your feedback. We will consider your suggestion for more seasoning.","We appreciate your input and will review our pricing.","We apologize if the portion size did not meet your expectations. We will take note of this for future updates to our menu.","Thank you for letting us know about the service. We will work on improving attentiveness.","We're sorry if the dish was too oily for your liking. We will work to adjust the recipe.","We will take your feedback into account to improve our presentation.","We're glad to hear you enjoyed the food. We will consider your input on the atmosphere.","Thank you for your feedback. We're glad you found the food flavorful.","We apologize if the presentation did not meet your expectations. We will work on improving this.","We appreciate your feedback on our pricing and will consider adjustments."};
	string bad_feedback[size] = {"We're sorry to hear that you didn't enjoy your meal. We'll do our best to make improvements to our menu.","We apologize for the inconvenience. Please let us know if there is anything we can do to make it up to you.","Thank you for bringing this to our attention. We will investigate and make sure this doesn't happen again.","We're sorry to hear that the food didn't meet your expectations. We strive to provide high-quality meals and will work to improve.","We apologize for the inconvenience and appreciate your feedback. We'll do our best to make sure this doesn't happen again.","We're sorry that the service wasn't up to par. We'll make sure to address this with our staff.","We apologize that the food didn't meet your taste preferences. We appreciate your feedback and will work to improve.","We're sorry that the portion size wasn't sufficient. We'll consider your feedback when updating our menu.","We apologize for the negative experience. Please let us know how we can make it right.","We're sorry to hear that you didn't enjoy your meal. We appreciate your feedback and will work to improve the dish." };

public:
	Feedback():id(0){};
	Feedback(int id) :id(id) {};
	int getRandomNumber();
	void input();

};	

int Feedback::getRandomNumber() 
{
	// Get the current time in seconds since the epoch
	time_t seed = time(0);

	// Use the current time as the seed for the random number generator
	srand(seed);

	//0-9
	int random_number = rand() % 10;
	//to get number 10
	++random_number;

	// Return the random number
	return random_number;
}

void Feedback::input()
{
	string text;
	cout << "Hey Sir! How was your meal? We would love to hear your feedback!(Single Word)" << endl;
	cin.ignore();
	getline(cin, text);

	//Ranged for loop
	for (int i ; i<text.length() ;i++) 
	{
		text[i] = tolower(text[i]);
	}

	// Can be modified later
	if (text == "good" ||text == "excellent" || text == "great" || text == "fantastic" || text == "delicious" || text == "amazing"|| text == "tasty"|| text == "flavorful"|| text == "mouthwatering"|| text == "delectable"|| text == "scrumptious"|| text == "yummy"|| text == "savory"|| text == "outstanding"|| text == "impressive"|| text == "phenomenal"|| text == "topnotch"|| text == "fabulous"|| text == "perfect"|| text == "superb"|| text == "terrific")
	{
		cout << good_feedback[getRandomNumber()] << endl;
	}

	else if (text == "okay" || text == "decent" || text == "satisfactory" || text == "average" || text == "adequate"|| text == "decent"|| text == "fine"|| text == "ok"|| text == "satisfactory"|| text == "acceptable"|| text == "fair"|| text == "passable"|| text == "average"|| text == "reasonable"|| text == "solid"|| text == "not bad"|| text == "notbad"|| text == "respectable")
	{
		cout << mod_feedback[getRandomNumber()] << endl;
	}

	else if (text == "terrible" || text == "disappointing" || text == "inedible" || text == "unappetizing" || text == "tasteless" || text=="bad" || text=="worst"|| text == "stale"|| text == "bland"|| text == "overcooked"|| text == "undercooked"|| text == "greasy"|| text == "fatty"|| text == "mushy"|| text == "sour"|| text == "bitter"|| text == "yucky")
	{
		cout << bad_feedback[getRandomNumber()] << endl;
	}

	else
	{
		cout << "Thankyou for your feedback! We value your feedback" << endl << endl;
	}
}
#endif // !FeedbackClass.h
