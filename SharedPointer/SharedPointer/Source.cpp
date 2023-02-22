#include<iostream>

template<class T>
class Shared_Pointer {
	T* sharedPtr;
	int* counter;
public:
	
	//Shared_Pointer() {
	//	std::cout << "\nDefault Constructor  of shared pointer is called\n";
	//	counter = new int(0);
	//	//std::cout << "\ncounter: " << *counter;

	//	//(*counter)++;
	//	//std::cout << "\ncounter: " << *counter;

	//}
	/*Shared_Pointer(T *pt) {
		sharedPtr = pt;
		std::cout << "\nDefault Constructor  of shared pointer is called\n";
		counter = 0;
		*counter++;
	}*/
	Shared_Pointer(T* Ptr = nullptr) {
		std::cout << "\nConstructor  of shared pointer is called\n";
		//std::cout << "\ncounter: " << counter;
		sharedPtr = Ptr;
		counter = new int(0);
		(*counter)++;
		//std::cout << "\ncounter: " << *counter;


	}
	Shared_Pointer(Shared_Pointer<T>& shPtr) {
		std::cout << "\nCopy Constructor  of shared pointer is called\n";
		sharedPtr = shPtr.sharedPtr;
		counter = shPtr.counter;
		(*counter)++;

	}
	T& operator=(Shared_Pointer<T>& shPtr)
	{
		std::cout << "\nCopy operator of shared pointer is called\n";
		sharedPtr = shPtr.sharedPtr;
		counter = shPtr.counter;
		(*counter)++;
		return *sharedPtr;

	}
	T& operator*()
	{
		return *sharedPtr;

	}
	T* operator->()
	{
		return sharedPtr;
	}
	T* get()
	{
		return sharedPtr;
	}
	~Shared_Pointer() {
		std::cout << "\nDestructor of shared pointer is called\n";
		counter++;

		if (counter == 0) {
			delete(sharedPtr);
			delete counter;
		}
	}
	int getCount()
	{
		return *counter;
	}
};

int main()
{

	Shared_Pointer<int> shPtr1(new int(2));
	//*shPtr1 = 100;
	//shPtr1 = 10;
	std::cout << "\n\nGet Count of shPtr1: "<< shPtr1.getCount() << "\n";

	Shared_Pointer<int> shPtr2;
	shPtr2 = shPtr1;
	std::cout << "\n\nGet Count of shPtr1: " << shPtr1.getCount() << "\n";
	
	Shared_Pointer<int> shPtr3(shPtr1);

	std::cout << "\n\nGet Count of shPtr1: " << shPtr1.getCount() << "\n";

	
	Shared_Pointer<int> shPtr4;
	shPtr4 = shPtr1;
	/*std::cout << "\n\nGet shPtr1: " << shPtr1.get() << "\n";
	std::cout << "\n\nGet shPtr1: " << shPtr2.get() << "\n";
	std::cout << "\n\nGet shPtr1: " << shPtr3.get() << "\n";
	std::cout << "\n\nGet shPtr1: " << shPtr4.get() << "\n";*/

	std::cout << "\n\nGet Count of shPtr1: " << shPtr1.getCount() << "\n";
	std::cout << "\n\nGet Count of shPtr4: " << shPtr4.getCount() << "\n";



	


	std::cout << "\n\n\n\n";

	return 0;
}