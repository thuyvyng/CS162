class Point{
	public:
		void set_x(int);
		void set_y(int);
		int get_x();
		int get_y();
		void translate(int,int);
		void print();
		Point();
		Point(int,int);

	private:
		int x;
		int y;

};
