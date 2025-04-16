#pragma once
/*
	Collection of cards, using unique pointers so that the card can only exist in once place at a time.
*/
#include <vector>
#include <memory>
#include "Cards/Card.h"

typedef std::vector<std::unique_ptr<Card>> CardCollection;
