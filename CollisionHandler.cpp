#include "stdafx.h"
#include "CollisionHandler.h"
#include "gameobjects.h"

void CollisionBetween(GameObjBase* p1, GameObjBase* p2) {
  p2->InvokeCollider(p1->ch);
  //p1->InvokeCollider(p2->ch);   // can be called symmetrically
  std::cout << "\t" << p1->name << " - " << p2->name << std::endl;
};

void CollisionBetween(Rock* rock, Paper* paper) {
  std::cout << "Rock wrapped by paper: " << std::endl;
};
void CollisionBetween(Rock* rock, Rock* rock1) {
  std::cout << "Rock ignores rock : " << std::endl;
};
void CollisionBetween(Rock* rock, Scissors* scissors) {
  std::cout << "Rock breaks scissors : " << std::endl;
};

void CollisionBetween(Scissors* scissors, Rock* rock) {
  std::cout << "Scissors break on rock: " << std::endl;
};
void CollisionBetween(Scissors* scissors, Paper* paper) {
  std::cout << "Scissors cut paper: " << std::endl;
};
void CollisionBetween(Scissors* scissors, Scissors* scissors1) {
  std::cout << "Scissors ignore scissors: " << std::endl;
};

void CollisionBetween(Paper* paper, Rock* rock) {
  std::cout << "Paper wraps rock: " << std::endl;
};
void CollisionBetween(Paper* paper, Paper* paper1) {
  std::cout << "Paper ignores paper: " << std::endl;
};
void CollisionBetween(Paper* paper, Scissors* scissors) {
  std::cout << "Paper cut by scissors: " << std::endl;
};