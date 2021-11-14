class Points
{	
private:
	int x;
	int y;
	int Z;

public:
	Points(): x(0), y(0), Z(0) {}
	Points(int x, int y, int Z): x(x), y(y), Z(Z){}
	~Points() {};
	
	bool compare()
	{
		int R = (int)sqrt(x * x + y * y);
		if (Z >= 10 or R <= 100) {
			return true;
		}
		else return false;		
	}

	int get_x() { return x; }
	int get_y() { return y; }
	int get_z() { return Z; }

	bool operator== (const Points& other) {		
		return this->x == other.x and
		       this->y == other.y and 
			   this->Z == other.Z;
	}

	bool operator!= (const Points& other) {
		return this->x != other.x or
			   this->y != other.y or
			   this->Z != other.Z;
	}

	friend bool operator <(const Points& l, const Points& r)
	{
		if (l.Z == r.Z)
		{
			if (l.y == r.y)
				return r.x < l.x;
			else
				return r.y < l.y;
		}
		else
			return l.Z < r.Z;
	}
	
	friend std::istream& operator >> (std::istream& is, Points&); 
	friend std::ostream& operator << (std::ostream& os, Points&);
};

std::istream& operator >> (std::istream& is, Points& p) {
	is >> p.x >> p.y >> p.Z;	  
	return is;
}

std::ostream& operator << (std::ostream& os, Points& p) {
	os << p.x << " " << p.y << " " << p.Z ;
	return os;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<Points> v;
	std::vector <std::pair<Points, int>> vp;
	if (n != 0)
	{
		for (int i = 0; i < n; ++i)
		{
			Points p;
			std::cin >> p;
			if (p.compare()) {
				v.push_back(p);
			}
		}

		sort(v.rbegin(), v.rend());

		while (!v.empty()) 
		{
			int value = count(v.begin(), v.end(), v.at(0));
			vp.push_back(std::make_pair(v.at(0), value));
			v.erase(v.begin(), v.begin() + value);
		}

		if (vp.size() > 1) 
		{
			for (int i = 1; i < vp.size(); ++i)
			{
				for (int j = 0; j < vp.size() - i; j++) {
					if (vp.at(j).first.get_z() == vp.at(j + 1).first.get_z()
						and vp.at(j).second < vp.at(j + 1).second)
						swap(vp.at(j), vp.at(j + 1));
				}
			}
		}
		
		for (int i = 0; i < vp.size(); ++i) {
			std::cout << vp.at(i).first << "  " << '\n';
		}
		std::cout << "\n";
	}
}
