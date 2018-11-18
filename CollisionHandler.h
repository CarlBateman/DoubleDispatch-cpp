#pragma once
//#include 
//#include 
//#include 
//#include 
#include <iostream>
#include <string>

struct GameObjBase;
struct Rock;
struct Paper;
struct Scissors;

template <class T1, class T2>
void CollisionBetween(T1* p1, T2* p2) {
  // generic/default handler or not handled
  std::cout << "CollisionBetween Not handled: " << typeid(p1).name() << " ~ " << typeid(p2).name() << std::endl;
};

template <class T1>
void CollisionBetween(T1* p1, GameObjBase* p2) {
  p2->InvokeCollider(p1->ch);
  //p1->InvokeCollider(p2->ch);  // can be called symmetrically
  std::cout << "\t" << p1->name << " - " << p2->name << std::endl;
};

template <class T2>
void CollisionBetween(GameObjBase* p1, T2* p2) {
  p2->InvokeCollider(p1->ch);
  //p1->InvokeCollider(p2->ch);  // can be called symmetrically
  std::cout << "\t" << p1->name << " - " << p2->name << std::endl;
};

void CollisionBetween(GameObjBase* p1, GameObjBase* p2);

void CollisionBetween(Rock* rock, Rock* rock1);
void CollisionBetween(Rock* rock, Paper* paper);
void CollisionBetween(Rock* rock, Scissors* scissors);

void CollisionBetween(Scissors* scissors, Rock* rock);
void CollisionBetween(Scissors* scissors, Paper* paper);
void CollisionBetween(Scissors* scissors, Scissors* scissors1);

void CollisionBetween(Paper* paper, Rock* rock);
void CollisionBetween(Paper* paper, Paper* paper1);
void CollisionBetween(Paper* paper, Scissors* scissors);

struct CollisionHandlerBase {
  virtual void Invoke(Rock*) { std::cout << "Invoke Not handled"; };
  virtual void Invoke(Paper*) { std::cout << "Invoke Not handled"; };
  virtual void Invoke(Scissors*) { std::cout << "Invoke Not handled"; };
};

/*
#define USE_DUMB_PTR
#define USE_AUTO_PTR
*/
#define USE_UNIQUE_PTR
#ifdef USE_DUMB_PTR
class CollisionHandler {
  CollisionHandlerBase* pImplementation;
public:
  CollisionHandler() : pImplementation(NULL) {};
  ~CollisionHandler() { delete(pImplementation); };
  void SetupCollisionHandler(CollisionHandlerBase* pImplementation) {
    delete(pImplementation);
    this->pImplementation = pImplementation;
  };
  template
    void Invoke(T t) { pImplementation->Invoke(t); };
};
#endif
#ifdef USE_AUTO_PTR
class CollisionHandler {
  std::auto_ptr pImplementation;
public:
  void SetupCollisionHandler(CollisionHandlerBase* pImplementation) {
    this->pImplementation.reset(pImplementation);
  };
  template
    void Invoke(T t) { pImplementation->Invoke(t); };
};
#endif
#ifdef USE_UNIQUE_PTR
class CollisionHandler {
  std::unique_ptr <CollisionHandlerBase> pImplementation;
public:
  void SetupCollisionHandler(CollisionHandlerBase* pImplementation) {
    this->pImplementation.reset(pImplementation);
  };
  template <class T>
    void Invoke(T t) { pImplementation->Invoke(t); };
};
#endif

template <class T>
class CollisionHandlerTemplate : public CollisionHandlerBase {
  T * target;
public:
  CollisionHandlerTemplate(T * target_) :target(target_) { };

  void Invoke(Rock* rock) { CollisionBetween(target, rock); };
  void Invoke(Paper* paper) { CollisionBetween(target, paper); };
  void Invoke(Scissors* scissors) { CollisionBetween(target, scissors); };
};