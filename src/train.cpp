// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCage(bool light) {
  Cage* mashine = new Cage();
  mashine->light = light;
  if (first == nullptr) {
    first = mashine;
    first->next = mashine;
    first->prev = mashine;
  } else {
    mashine->next = first;
    mashine->prev = first->prev;
    (first->prev)->next = mashine;
    first->prev = mashine;
  }
}

int Train::getLength() {
  int length = 0;
  first->light = true;
  while (first->light) {
    length = 0;
    Cage* cur_mashine = first->next;
    countOp++;
    length++;
    while (!cur_mashine->light) {
      countOp++;
      length++;
      cur_mashine = cur_mashine->next;
    }
    cur_mashine->light = false;
  }
  countOp *= 2;
  return length;
}

int Train::getOpCount() {
  return countOp;
}
