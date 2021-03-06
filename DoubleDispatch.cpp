// DoubleDispatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "gameobjects.h"
#include "CollisionHandler.h"

void main() {
  Rock rock, rock1;
  rock.name = "Pierre";
  rock1.name = "Rocky";
  Paper paper;
  paper.name = "Whitey";
  Scissors scissors;
  scissors.name = "Snippy";

  GameObjBase* pRock = &rock;
  GameObjBase* pRock1 = &rock1;
  GameObjBase* pPaper = &paper;
  GameObjBase* pScissors = &scissors;

  std::cout << "rock* & scissors" << std::endl;
  CollisionBetween(pRock, &scissors);
  std::cout << std::endl;
  std::cout << "scissors & rock*" << std::endl;
  CollisionBetween(&scissors, pRock1);
  std::cout << std::endl;
  CollisionBetween(pRock, pRock1);

  std::vector<GameObjBase*> vecGameObjBase;
  vecGameObjBase.push_back(pRock);
  vecGameObjBase.push_back(pPaper);
  vecGameObjBase.push_back(pScissors);

  for (size_t i = 0; i < vecGameObjBase.size(); i++) {
    for (size_t j = 0; j < vecGameObjBase.size(); j++) {
      CollisionBetween(vecGameObjBase[i], vecGameObjBase[j]);
    }
    std::cout << std::endl;
  }

  std::cin.get();
}