#include "stdafx.h"
#include "gameobjects.h"

Rock::Rock() { SetupCollisionHandler(ch, this); };
void Rock::InvokeCollider(CollisionHandler& ch) { ch.Invoke(this); }

Paper::Paper() { SetupCollisionHandler(ch, this); };
void Paper::InvokeCollider(CollisionHandler& ch) { ch.Invoke(this); }

Scissors::Scissors() { SetupCollisionHandler(ch, this); };
void Scissors::InvokeCollider(CollisionHandler& ch) { ch.Invoke(this); }