#include "Indexer.h"
#include "Intersections.h"
#include "Josephus.h"
#include "IO_text.h"
int main(){
	IO_text Message;
	int selection =-1;
	bool escape = false;

	//Menu format for running individual source files.
	while (!escape) {
		Message.Show("\nMENU");
		Message.Show("Select an option below:");
		Message.Show("Option 1: ", Indexer::ID());
		Message.Show("Option 2: ", Intersections::ID());
		Message.Show("Option 3: ", Josephus::ID());
		Message.Prompt(selection, "Specify a number to run a program otherwise enter 0 to quit: ", 0, 2);
		switch (selection) {
		case 1: Indexer::maindev(); 		break;
		case 2: Intersections::maindev();	break;
		//case 3: Josephus::maindev(); break;				//Implementation in future stages
		case 0: escape = Message.Question("quit");
		}
		
	}
}