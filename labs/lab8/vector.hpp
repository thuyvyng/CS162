#include <stdlib.h>
#include <stdexcept>
template <class T>

//using std::exception;
//using std:: out_of_range;
class vector{
	private:
		T *v;
		int s;
	public:
		vector(){
			s = 0;
			v = NULL;
		}
		//copy constructor
		vector(vector<T> &other){
			s = other.s;
			
			if (s == 0)
				v = NULL;
			else{
				v = new T[s];
				for (int i = 0; i < s; i++){
					v[i] = other.v[i];		
				}
			}	 
		}
		//assignment operator overload
		void operator=(vector<T> &other){
			s = other.s;
			if (v != NULL)
				delete [] v;
			if (s == 0)
				v = NULL;
			else{
				v = new T[s];
				for (int i = 0; i < s; i++){
					v[i] = other.v[i];		
				}
			}
		}
		~vector(){
			delete [] v;

		}
		//only performs address arithmetic
		T operator[] (int n){
			return v[n];

		}

		//checks to make sure its not out of bonds
		T at(int n){
			if ( n >= s){
				throw std:: out_of_range("out of vector bounds");

			}

		}
		int size(){
			return s;
		}
		void push_back(T ele){
			T*temp;
			temp = new T[++s];
			for (int i =0; i <s-1; i++)
				temp[i] = v[i];

			delete []v;
			v = temp;
			v[s-1] = ele;

		}
};
