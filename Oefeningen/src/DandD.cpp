/*
 * DandD.cpp
 *
 *  Created on: 6-dec.-2013
 *      Author: arno
 */

#include <iostream>
#include <vector>
#include <typeinfo> //typeid(..).name() functie
typedef std::string Str;

class Item {
public:

	Item(const Str& name, int w) :
			name_(name), weight_(w) {

	}

	virtual ~Item() {

	}

	Str getName() const {
		return name_;
	}

	void setName(Str name) {
		this->name_ = name;
	}

	int getWeight() const {
		return weight_;
	}

	void setWeight(int weight) {
		this->weight_ = weight;
	}

	virtual void printOp(std::ostream& out) {
		out << "Item type: Normal item" << std::endl << "Item name:"
				<< getName() << std::endl << "Item Weight:" << getWeight();
	}

private:
	Str name_;
	int weight_;
};

std::ostream& operator<<(std::ostream& out, Item& it) {
	it.printOp(out);
	return out;
}

class Weapon: public Item {
public:
	Weapon(const Str& n, int w, int a) :
			Item(n, w), attack_(a) {

	}
	int getAttack() const {
		return attack_;
	}
	virtual void printOp(std::ostream& out) {
		out << "Item type: Weapon" << std::endl << "Item name:" << getName()
				<< std::endl << "Item Weight:" << getWeight() << std::endl
				<< "Attack strength:" << getAttack();
	}

private:
	int attack_;

};
class Armor: public Item {
public:
	Armor(const Str& n, int w, int d) :
			Item(n, w), defense_(d) {

	}
	int getDefense() const {
		return defense_;
	}
	virtual void printOp(std::ostream& out) {
		out << "Item type: Weapon" << std::endl << "Item name:" << getName()
				<< std::endl << "Item Weight:" << getWeight() << std::endl
				<< "Defense Power:" << getDefense();
	}

private:
	int defense_;

};

class Bag: public Item {
public:
	Bag(int w) :
			Item(Str("Bag"), w) {

	}

	~Bag() {
		for (std::vector<Item*>::iterator it = in_bag_.begin();
				it != in_bag_.end(); ++it) {
			delete (*it);
		}
	}

	void add(Item* it) {
		in_bag_.push_back(it);
	}

	virtual void printOp(std::ostream& out) {
		out << "Item type: Bag" << std::endl << "Item name:" << getName()
				<< std::endl << "Item Weight:" << getWeight() << std::endl
				<< "Number of items:" << num_items();
	}

	int num_items() const {
		return in_bag_.size();
	}

	int total_size() const {
		int ret(getWeight());
		for (std::vector<Item*>::const_iterator it = in_bag_.begin();
				it != in_bag_.end(); ++it) {
			ret += (**it).getWeight();
		}
		return ret;
	}

	std::ostream& printContent(std::ostream& out) {
		printOp(out);
		out << std::endl << "Items:" << std::endl;
		for (std::vector<Item*>::const_iterator it = in_bag_.begin();
				it != in_bag_.end(); ++it) {
			(**it).printOp(out);
			out << std::endl;
		}
		return out;
	}
private:
	std::vector<Item*> in_bag_;
};

class Character {
public:
	Character(const Str& name, int age) :
			bag(new Bag(4)), name_(name), age_(age), weapon_(NULL), armor_(NULL) {
	}
	~Character() {
		delete weapon_;
		delete armor_;
		delete bag;
	}
	void equipWeapon(Item * w) {
		Weapon * cur_w = dynamic_cast<Weapon*>(w);
		if (cur_w != NULL) {
			weapon_ = cur_w;
		} else {
			throw Str("Error verkeerd type").append(typeid(*w).name());
		}
	}
	void equipArmor(Item * w) {
		Armor * cur_w = dynamic_cast<Armor*>(w);
		if (cur_w != NULL) {
			armor_ = cur_w;
		} else {
			throw Str("Error verkeerd type").append(typeid(*w).name());
		}
	}

	int getAge() const {
		return age_;
	}

	Str getName() const {
		return name_;
	}
	Str getWeapon() const {
		Str ret;
		if (weapon_ == NULL) {
			ret = Str("None");
		} else {
			ret = weapon_->getName();
		}
		return ret;
	}
	Str getArmor() const {
		Str ret;
		if (armor_ == NULL) {
			ret = Str("None");
		} else {
			ret = armor_->getName();
		}
		return ret;
	}
	std::ostream& printOverview(std::ostream& out) {
		out << "Name: " << getName() << " (" << getAge() << ")" << std::endl
				<< "Weapon: " << getWeapon() << std::endl << "Armor: "
				<< getArmor() << std::endl;
		bag->printContent(out);
		return out;
	}
	Bag* bag;
private:
	Str name_;
	int age_;
	Weapon* weapon_;
	Armor* armor_;
};

int main() {
	Character c(Str("Arno"), 18);
	Weapon * w = new Weapon(Str("Dolk"), 1, 1);
	Armor * a = new Armor(Str("Schild"), 10, 4);
	Armor * aa = new Armor(Str("Chain"), 5, 3);
	c.bag->add(aa);
	try {
		c.equipArmor(a);
		c.equipWeapon(w);
	} catch (Str& s) {
		std::cout << s;
	}
	c.printOverview(std::cout);
	return 0;
}

