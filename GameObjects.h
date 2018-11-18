#pragma once
#include "CollisionHandler.h"

struct GameObjBase {
  std::string name;
  CollisionHandler ch;
  virtual void InvokeCollider(CollisionHandler& ch) = 0;

  template <class T>
    void SetupCollisionHandler(CollisionHandler& ch, T* t) {
    ch.SetupCollisionHandler(new CollisionHandlerTemplate<T>(t));
  }
};

struct Rock : GameObjBase {
  Rock();
  void InvokeCollider(CollisionHandler& ch);
};

struct Paper : GameObjBase {
  Paper();
  void InvokeCollider(CollisionHandler& ch);
};

struct Scissors : GameObjBase {
  Scissors();
  void InvokeCollider(CollisionHandler& ch);
};