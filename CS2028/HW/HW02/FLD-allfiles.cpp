#include <stddef.h>
#include  <list>
#include <iostream>
#include <string>

using namespace std;

//window, door, opening 
struct opening{
	char side; //l - left, t - top, r - right, b - bottom
	int dist; // Distance from origin of side
	int length; //length of  opening
	char type; //d - door, w- window, o -opening, u - unknown
};

struct connection{
	char side; //l - left, t - top, r - right, b - bottom
	string name; // name of room
};

//private or public space
class block{

private:
	int length;
	int width;
	char type; //r - room or s - space or u - unassigned
	int originX;
	int originY; //coordinates of room 
	string name; // name of room
	list<opening> interfaces; //window, door, opening 
	list<connection> connections; //topology 
	
public:
	block();
	block(int len, int wid, char t, int x, int y, string n);
	~block();
	void addBlockAttributes(int len, int wid, char t, int x, int y, string n);
	void addInterface(opening o); //openings in rooms-- windows, doors, etc 
	void addTopology(connection c);
	int computeArea(); //area of room 
	bool isPublic();
	void printBlock();
};

	block::block(){
		length = 0;
		width = 0;
		type = 'u'; //room or space or unassigned
		originX = 0;
		originY = 0;
		name = "";
	};
	
	
	block::block(int len, int wid, char t, int x, int y, string n){
		length = len;
		width = wid;
		type = t; //r - room or s - space
		originX = x;
		originY = y;
		name = n; // name of room 
	};
	
	block::~block(){
	};
	
	void block::addBlockAttributes(int len, int wid, char t, int x, int y, string n){
		length = len;
		width = wid;
		type = t; //r - room or s - space
		originX = x;
		originY = y;
		name = n;
	};
	
	void block::addInterface(opening o){
		interfaces.push_back(o); //opening of room 
	};
			
	
	void block::addTopology(connection c){
		connections.push_back(c); //coonection with other room 
	};

	int block::computeArea(){
		int area;
		area = length * width;
		return area;
	}
	
	bool block::isPublic(){
		if (type != 'r') return true;
		else return false; //difference between public and private room 
	}
	
	void block::printBlock(){
		cout << "Block " << name << endl;
		cout << "Length " << length << endl;
		cout << "Width " << width << endl;
		cout << "Coordinates (" << originX << "," << originY << ")" << endl;
		cout << "Type: " << type << endl;
		list<opening>::iterator it;
		// Iterating over list elements 
		it = interfaces.begin();
		cout << "Openings" << endl;
		while(it != interfaces.end())
		{
			cout << "Type: " << it->type << endl;
			cout << "Distance: " << it->dist << endl;
			cout << "Side: " << it->side << endl;
			cout << "Length: " << it->length << endl;
					
			it++;
		}
		list<connection>::iterator it2;
		// Iterating over list elements 
		it2 = connections.begin();
		cout << "Connections" << endl;
		while(it2 != connections.end())
		{
			cout << "Side: " << it2->side << endl;
			cout << "Name: " << it2->name << endl;		
			it2++;
		}
	}
	
struct dimension{
	int length;
	int width;
};


class home{
private:
	dimension d;
	list<block> blocks;
public:
	home();
	~home();	
	home (int len, int wid);
	int addBlock(block b);
	int addBlock(int l, int w, char t, int x, int y, string s);
	void addInterface(block* b, opening o);
	void addTopology(block* b, connection c);
	int computeHomeArea();
	int computePublicArea();
	int computePrivateArea(); //area of both private and public areas
	void printLayout();
};

	home::home(){
		d.length = 0;
		d.width = 0;
	};
	
	home::~home(){
	};
		
	home::home(int len, int wid){
		d.length = len;
		d.width = wid; //for room specifications 
	};
	
	int home::addBlock(block bk){
		blocks.push_back(bk);
	}
	
	int home::addBlock(int l, int w, char t, int x, int y, string s){
		block b(l, w, t, x, y, s);
		blocks.push_back(b);
		return 0;
	};
	
	void home::addInterface(block* b, opening o){
		b->addInterface(o);
	};
	
	void home::addTopology(block* b, connection c){
		b->addTopology(c);
	}
	
	
	int home::computeHomeArea(){
		int area;
		area = d.length * d.width;
		return area;
	};
	
	int home::computePublicArea(){
		int publicA = 0;
		list<block>::iterator it;
		// Iterating over list elements 
		it = blocks.begin();
		while(it != blocks.end())
		{
			if (it->isPublic()){
				publicA = publicA + it->computeArea();
			}		
			it++;
		}
		return publicA;
	};
	int home::computePrivateArea(){
		int privateA = 0;
		list<block>::iterator it;
		// Iterating over list elements 
		it = blocks.begin();
		while(it != blocks.end())
		{
			if (!it->isPublic()){
				privateA = privateA + it->computeArea();
			}		
			it++;
		}
		return privateA;
	};

	void home::printLayout(){
		//print each block
		list<block>::iterator it;
		it = blocks.begin();
		while(it != blocks.end())
		{
			it->printBlock();
			it++;
		}	
	};


int main(){
int hw, hl, rw, rl, rx, ry;
string responser, responsec, responsei;
char t;
string rn;
block b;
opening o;
connection c;


cout << "Enter home width" << endl;
cin >> hw;
cout << "Enter home length" << endl;
cin >> hl;
//create home;
home h = home(hl,hw);
 
//put a loop till no more rooms need to be entered
cout << " Enter Room? (Yes/No)" << endl;
cin >> responser;
//cout << responser;
while (responser.compare("No") != 0){

	cout << "Enter room width" << endl;
	cin >> rw;
	cout << "Enter room length" << endl;
	cin >> rl;
	cout << "Enter room name" << endl;
	cin >> rn;
	cout << "Enter room type" << endl;
	cin >> t;
	cout << "Enter room x coordinate" << endl;
	cin >> rx;
	cout << "Enter room y coordinate" << endl;
	cin >> ry;
	b.addBlockAttributes(rl, rw, t, rx, ry, rn);
//get interfaces and connections
	cout << "Enter interface?" << endl;
	cin >> responsei;
	while (responsei.compare("No") != 0){
		cout << "Enter side: " << endl;
		cin >> o.side;
		cout << "Enter distance from origin: " << endl;
		cin >> o.dist;
		cout << "Enter length: " << endl;
		cin >> o.length;
		cout << "Enter interface type: " << endl;
		cin >> o.type;
		b.addInterface(o);
		cout << " Enter interface? (Yes/No)" << endl;
		cin >> responsei;
	}
	cout << "Enter connection?" << endl;
	cin >> responsec;
	while (responsec.compare("No") != 0){
		cout << "Enter side: " << endl;
		cin >> c.side;
		cout << "Enter room name: " << endl;
		cin >> c.name;
		b.addTopology(c);
		cout << " Enter interface? (Yes/No)" << endl;
		cin >> responsec;
	}
//add block to home
	h.addBlock(b);
	cout << " Enter Room? (Yes/No)" << endl;
	cin >> responser;
}
h.printLayout();
cout << "Home Area: " << h.computeHomeArea() << endl;
cout << "Public Area: " << h.computePublicArea() << endl;
cout << "Private Area: " << h.computePrivateArea() << endl;
}
