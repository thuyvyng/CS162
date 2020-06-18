#include <iostream>
#include <string>

using namespace std;


class Show{
	private:
		string title;
		string director;
		float time;
		int num_characters;
		string * characters;

	public:
		Show();
		Show(string,string,float,int);

		//accessors

		string get_title() const;
		string get_director() const;
		float get_time() const;
		int get_num_char() const;
		string get_name_char (int) const;

		//mutators
		
		void set_title(string);
		void set_director(string);
		void set_time(float);
		void set_num_characters(int);
		void set_chars_name(int);




};
