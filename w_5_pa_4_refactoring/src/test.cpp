#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Men {
public:
    Men(const std::string& type,const std::string& name):_type(type),_name(name){}
    virtual void Walk(const std::string destination) const =0;
    virtual ~Men(){}
    std::string Type(void ) const{return _type;}
    std::string Name(void ) const{return _name;}
private:
    const std::string _type;
    const std::string _name;
};


class Student:public Men {
public:

    Student(const std::string& name,const std::string& favouriteSong):\
        Men("Student", name),_favouriteSong(favouriteSong){}


    void Walk(string destination) const override {
        cout << Type()+": " << Name() << " walks to: " << destination << endl;
        cout << Type()+": " << Name() << " sings a song: " << _favouriteSong << endl;
    }

    void Learn() {
        cout << Type()+": " << Name() << " learns" << endl;
    }

    void SingSong() {
        cout << Type()+": " << Name() << " sings a song: " << _favouriteSong << endl;
    }

public:
private:
    const string _favouriteSong;
};


class Teacher:public Men {
public:

    Teacher(const std::string& name,const std::string& subject):\
        Men("Teacher", name),_subject(subject){}

    void Walk(string destination) const override {
        cout << Type()+": " << Name() << " walks to: " << destination << endl;
    }

    void Teach() {
        cout << "Teacher: " << Name() << " teaches: " << _subject << endl;
    }


private:
    const string _subject;
};


class Policeman:public Men {
public:
    Policeman(const std::string& name):\
        Men("Policeman", name){}

    void Walk(string destination) const override {
        cout << Type()+": " << Name() << " walks to: " << destination << endl;
    }

    void Check(const Men& t) {
        cout << "Policeman: " << Name() << " checks "<< t.Type()<<". "<< t.Type()+"'s name is: " << t.Name() << endl;
    }

};


void VisitPlaces(const Men& t,const vector<string>& places) {
    for (auto p : places) {
        t.Walk(p);
    }
}

/*
int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
*/
