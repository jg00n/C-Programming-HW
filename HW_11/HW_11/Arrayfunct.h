#pragma once
/*
*    Return type 	Function name	Arguments 	             	Tasks
*    T 	            Minimum         An array of T called Arr    This function cycles through Arr, finding the lowest value, and returning it.
*    T				Maximum			An array of T called Arr	This function cycles through Arr, finding the highest value, and returning it.
*    
*    
*/
namespace Num {
	//Checks numbers
	template<class T>
	T Minimum(T Arr[], const int INDEX) {
		//Check mininimum
		T min = 999999;
		for (int i = 0; i < INDEX; i++) {
			if (Arr[i] < min) min = Arr[i];
		}
		return min;
	}
	template<class T>
	T Maximum(T Arr[], const int INDEX) {
		//Check Maximum.
		T max = -999999;
		for (int i = 0; i < INDEX; i++) {
			if (Arr[i] > max) max = Arr[i];
		}
		return max;
	}
}