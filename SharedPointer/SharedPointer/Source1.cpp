//#include <iostream>
//
//struct Point {
//	int x;
//	int y;
//	int z;
//public:
//	Point()
//	{
//		std::cout << "\nin Point's default constructor";
//
//	}Point(int a, int b, int c)
//	{
//		std::cout << "\nin Point constructor";
//
//	}
//	~Point() {}
//	//copy constructor
//	Point(const Point& pt)
//	{
//		x = pt.x;
//		y = pt.y;
//		z = pt.z;
//		std::cout << "\nin Point's copy constructor";
//	}
//	//move constructor
//	Point(Point&& pt)
//	{
//		std::cout << "\nin Point's Move constructor";
//	}
//	Point& operator*() {
//
//		std::cout << "\nin \"*\" operator ";
//
//	}
//	Point& operator=(Point pt) {
//		std::cout << "\nin \"=\" operator ";
//
//		return pt;
//	}
//	void PrintX() {
//		std::cout << "\nX:" << this->x;
//
//	}
//	int PointX() {
//		return this->x;
//	}
//};
//
//// Class representing a reference counter class
//class Counter
//{
//	int count;
//public:
//	// Constructor
//	Counter()
//	{
//		std::cout << "\n\n\nCounter Constructor\n\n\n";
//		count = 0;
//	}
//
//	// Destructor
//	~Counter() {
//		std::cout << "\n\n\nCounter Destructor\n\n\n";
//	}
//
//	void reset()
//	{
//		count = 0;
//	}
//
//	unsigned int get()
//	{
//		return count;
//	}
//
//	// Overload post/pre increment
//	void operator++()
//	{
//		//std::cout << "++ operator";
//		count++;
//	}
//
//	void operator++(int)
//	{
//		count++;
//	}
//
//	// Overload post/pre decrement
//	void operator--()
//	{
//		count--;
//	}
//	void operator--(int)
//	{
//		count--;
//	}
//
//};
//
//
//
//template<typename T>
//class Shared_Pointer {
//	T* sharedPtr;
//	Counter* counter;
//	//int* counter;
//public:
//
//	/*Shared_Pointer() {
//		std::cout << "\nDefault Constructor  of shared pointer is called\n";
//		counter = new Counter();
//		(*counter)++;
//	}*/
//	Shared_Pointer(T* ptr = nullptr)
//	{
//		std::cout << "\nConstructor  of shared pointer is called\n";
//
//		sharedPtr = ptr;
//		counter = new Counter();
//		counter->operator++();
//	}
//
//	Shared_Pointer(Shared_Pointer<T>& shPtr) {
//		std::cout << "\nCopy Constructor  of shared pointer is called\n";
//		sharedPtr = shPtr.sharedPtr;
//		counter = shPtr.counter;
//		counter->operator++();
//		//std::cout << "\ncounter: " << counter << "\n";
//
//	}
//	T& operator=(Shared_Pointer<T>& shPtr)
//	{
//		std::cout << "\nCopy operator =  of shared pointer is called\n";
//		sharedPtr = shPtr.sharedPtr;
//		counter = shPtr.counter;
//		counter->operator++();
//		return *sharedPtr;
//		//std::cout << "\ncounter: " << counter << "\n";
//	}
//	T* get()
//	{
//		return sharedPtr;
//	}
//	unsigned int use_count()
//	{
//		return counter->get();
//	}
//
//	T& operator*()
//	{
//		return *sharedPtr;
//
//	}
//
//	T* operator->()
//	{
//		return sharedPtr;
//	}
//	~Shared_Pointer() {
//		std::cout << "\nDestructor of shared pointer is called\n";
//		counter->operator--();
//		if (counter == 0) {
//			delete(sharedPtr);
//			delete counter;
//		}
//	}
//};
//
//int main()
//{
//	//..........Example with Point class.....
//	//std::cout << "\n\n\n.........Example with Point class.....\n\n\n ";
//
//	//Point p1(12, 13, 44);
//	////p1.PointX();
//
//	//Shared_Pointer<Point> sharedPointer(new Point(1004, 24, 24));
//	//std::cout << "\n\n\sharedPointer'count: " << sharedPointer.use_count();
//	////std::cout << "\n\n\nptr1's value now: " << << std::endl;
//
//	//Shared_Pointer<Point> sharedPointer2(sharedPointer);
//	//std::cout << "\n\n\sharedPointer'count: " << sharedPointer.use_count() << std::endl << std::endl;
//	//std::cout << "\n\n\sharedPointer2'count: " << sharedPointer2.use_count() << std::endl << std::endl;
//	//std::cout << "\n\n\sharedPointer value of x: ";
//	//sharedPointer->PrintX();
//	//std::cout << "\n\n\sharedPointer value of x: " << sharedPointer->PointX();
//	//std::cout << "\n\n\sharedPointer value of x: " << *sharedPointer.PointX(); 
//
//	
//	Shared_Pointer<int> shPtr1(new int(42));
//    //*shPtr1 = 100;
//	std::cout << "\n\n\shPtr1'count: " << shPtr1.use_count();
//	std::cout << "\n\n\shPtr1's value now: " << *shPtr1 << std::endl;
//
//	Shared_Pointer<int> shPtr2(shPtr1);
//	std::cout << "\n\n\shPtr1'count: " << shPtr1.use_count() << std::endl << std::endl;
//	//shPtr1 = 10;
//	//std::cout << (int)shPtr1.getCount() / sizeof(int) << "\n";
//
//	Shared_Pointer<int> shPtr3(shPtr1);
//	std::cout << "\n\n\nptr1'count: " << shPtr1.use_count() << std::endl << std::endl;
//	Shared_Pointer<int> shPtr4;
//	shPtr4 = shPtr1;
//	std::cout << "\n\n\nptr1'count: " << shPtr1.use_count() << std::endl << std::endl;
//	std::cout << "\n\n\nptr4'count: " << shPtr4.use_count() << std::endl << std::endl;
//
//
//
//
//	////..............New Example............
//	//std::cout << "\n\n\n.............New Example...........\n\n\n" << std::endl;
//
//
//
//	//Shared_Pointer<char> shPointer(new char('a'));
//	////*shPtr1 = 100;
//	//std::cout << "\shPointer'count: " << shPointer.use_count();
//	//std::cout << "\n\n\shPointer's value now: " << *shPointer << std::endl;
//
//	//Shared_Pointer<char> shPointer2;
//	//shPointer2 = shPointer;
//	//std::cout << "\n\n\shPointer'count: " << shPointer.use_count() << std::endl << std::endl;
//	//std::cout << "\n\n\shPointer2'count: " << shPointer2.use_count() << std::endl << std::endl;
//	////shPtr1 = 10;
//	////std::cout << (int)shPtr1.getCount() / sizeof(int) << "\n";
//
//	
//
//
//
//
//	
//	return 0;
//}
