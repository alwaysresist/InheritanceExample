#include<iostream>
#include<string>
#include<clocale>
using namespace std;

class ComputerGameObject
{
private:
	string Name;
protected:
	ComputerGameObject(const string& _Name) :Name(_Name) {}
	ComputerGameObject(const ComputerGameObject& obj) : Name(obj.Name) {}
	virtual ~ComputerGameObject() {}
	virtual void  _print() const {
		cout << " Name: " << Name;
	}
public:
	virtual void draw() = 0;
	void  print() const
	{
		cout << typeid(*this).name() << "\n";
		_print();
		cout << "\n\n";
	}
};
class Creature :public ComputerGameObject
{
private:
	int healthPoints;
	int dx;
	int dy;
	int endurance;
public:
	Creature(const string& _Name, int _healthPoints, int _endurance) :ComputerGameObject(_Name), healthPoints(_healthPoints), endurance(_endurance), dx(0), dy(0) {}
	Creature(const Creature& obj) :
		ComputerGameObject(obj), healthPoints(obj.healthPoints), dx(obj.dx), dy(obj.dy), endurance(obj.endurance) {}
	Creature(const string& _Name, int _healthPoints, int _dx, int _dy, int _endurance) :
		ComputerGameObject(_Name), healthPoints(_healthPoints), dx(_dx), dy(_dy), endurance(_endurance) {}
	void _move(int X, int Y) {
		dx = X;
		dy = Y;
	}
	int getx() {
		return dx;
	}
	int gety() {
		return dy;
	}
	~Creature() {}
protected:
	virtual void move(int, int) = 0;
	void  _print()const override
	{
		ComputerGameObject::_print();
		cout << "\n Health points: " << healthPoints << "\n Coordinate x: " << dx << "\n Coordinate y: " << dy << "\n Endurance: " << endurance;
	}
};
class MythicalAnimal :public Creature
{
private:
	bool mythicalAbilities;
public:
	MythicalAnimal(const string& _Name, int _healthPoints, int _endurance, bool _mythicalAbilities) :Creature(_Name, _healthPoints, _endurance), mythicalAbilities(_mythicalAbilities) {}
	MythicalAnimal(const MythicalAnimal& obj) : Creature(obj), mythicalAbilities(obj.mythicalAbilities) {}
	MythicalAnimal(const string& _Name, int _healthPoints, int _dx, int _dy, int _endurance, bool _mythicalAbilities) :
		Creature(_Name, _healthPoints, _dx, _dy, _endurance), mythicalAbilities(_mythicalAbilities) {}
	~MythicalAnimal() {}
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Mythical animal moved to: (" << getx() << ";" << gety() << ")" << endl;
	}
	void draw()
	{
		cout << "Coordinates of a mythical animal: (" << getx() << ";" << gety() << ")\n";
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << "\n Mythical abilities: " << mythicalAbilities;
	}
};
class Human :public Creature
{
private:
	int weaponsCount;
	int lvl;
public:
	Human(const string& _Name, int _healthPoints, int _endurance, int _weaponsCount, int _height) :Creature(_Name, _healthPoints, _endurance), weaponsCount(_weaponsCount), lvl(_height) {}
	Human(const Human& obj) : Creature(obj), weaponsCount(obj.weaponsCount), lvl(obj.lvl) {}
	Human(const string& _Name, int _healthPoints, int _dx, int _dy, int _endurance, int _weaponsCount, int _height) :
		Creature(_Name, _healthPoints, _dx, _dy, _endurance), weaponsCount(_weaponsCount), lvl(_height) {}
	~Human() {}
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Human character moved to: (" << getx() << ";" << gety() << ")" << endl;
	}
	void draw() override
	{
		cout << "Coordinates of a humanoid character: (" << getx() << ";" << gety() << ")\n";
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << "\n Number of weapons: " << weaponsCount << "\n lvl: " << lvl;
	}
};
class MagicCharacter :public Creature
{
private:
	string manaCount;
public:
	MagicCharacter(const string& _Name, int _healthPoints, int _endurance, string _manaCount) :Creature(_Name, _healthPoints, _endurance), manaCount(_manaCount) {}
	MagicCharacter(const MagicCharacter& obj) : Creature(obj), manaCount(obj.manaCount) {}
	MagicCharacter(const string& _Name, int _healthPoints, int _dx, int _dy, int _endurance, string _manaCount) :
		Creature(_Name, _healthPoints, _dx, _dy, _endurance), manaCount(_manaCount) {}
	~MagicCharacter() {}
	void move(int X, int Y) override {
		Creature::_move(X, Y);
		cout << "Magic character moved to: (" << getx() << ";" << gety() << ")" << endl;
	}
	void draw() override
	{
		cout << "Coordinates of a magic character: (" << getx() << ";" << gety() << ")\n";
	}
protected:

	void _print()const override
	{
		Creature::_print();
		cout << "\n Count of mana: " << manaCount;
	}
};
class MagicItem :public ComputerGameObject
{
private:
	int id;
	int dx;
	int dy;
	int power;
public:
	MagicItem(const string& _id) :ComputerGameObject(_id), dx(0), dy(0), id(0), power(0) {}
	MagicItem(const string& _Name, int _id, int _power) :ComputerGameObject(_Name), id(_id), power(_power), dx(0), dy(0) {}
	MagicItem(const string& _Name, int _id, int _power, int _dx, int _dy) :
		ComputerGameObject(_Name), id(_id), power(_power), dx(_dx), dy(_dy) {}
	MagicItem(const MagicItem& obj) :ComputerGameObject(obj), dx(obj.dx), dy(obj.dy), id(obj.id), power(obj.power) {}
	~MagicItem() {}
	void draw() override
	{
		cout << "Coordinates of a magic item: (" << dx << ";" << dy << ")\n";
	}
protected:
	void _print()const override
	{
		ComputerGameObject::_print();
		cout << "\n id: " << id << "\n Power: " << power << "\n Coordinate x: " << dx << "\n Coordinate y: " << dy;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	Human human("Dura4ek", 100, -50, 50, 50, 5, 15);
	human.move(100, -100);
	human.draw();
	human.print();

	MythicalAnimal Eagle("Eagle", 50, -50, 1);
	Eagle.move(100, 150);
	Eagle.draw();
	Eagle.print();

	MagicCharacter Mage("Mage", 100, 50, "");
	Mage.move(1000, 50);
	Mage.draw();
	Mage.print();

	MagicItem Bow("Bow", 1, 5);
	Bow.draw();
	Bow.print();
}

