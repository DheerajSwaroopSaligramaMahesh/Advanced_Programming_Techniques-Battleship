#include <iostream>
#include <cstdlib>
#include <string>

#include "testFiles.h"

int main()
{
	// TODO: Add your program code here
	std::cout << "Battleship started." << std::endl << std::endl;
	part1tests();
	part2tests();
	part3tests();

	Board b1(10, 10);
	ConsoleView view(&b1);

	//placing valid ships
	Ship shipA(GridPosition("B2"), GridPosition("B4"));
	Ship shipB(GridPosition("D4"), GridPosition("G4"));
	Ship shipC(GridPosition("F6"), GridPosition("F9"));
	b1.getOwnGrid().placeShip(shipA);
	b1.getOwnGrid().placeShip(shipB);
	b1.getOwnGrid().placeShip(shipC);

	b1.getOwnGrid().takeBlow(GridPosition("B3"));
	b1.getOwnGrid().takeBlow(GridPosition("B4"));
	b1.getOwnGrid().takeBlow(GridPosition("B5"));

	b1.getOpponentGrid().shotResult(GridPosition("C3"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("C4"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("C5"), Shot::Impact::SUNKEN);
	b1.getOpponentGrid().shotResult(GridPosition("C2"), Shot::Impact::NONE);
	b1.getOpponentGrid().shotResult(GridPosition("F5"), Shot::Impact::NONE);
	b1.getOpponentGrid().shotResult(GridPosition("G4"), Shot::Impact::NONE);
	b1.getOpponentGrid().shotResult(GridPosition("G5"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("G6"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("I5"), Shot::Impact::NONE);

	view.print();

	std::cout << std::endl;

	return 0;
}
