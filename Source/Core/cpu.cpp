#include "cpu.h"

CPU::CPU()
{
	delayTimer = 0;
	soundTimer = 0;

	timeKeeper.Restart();

	currentInstructionCount = INSTRUCTIONS_PER_FRAME;

	PC = 0x200;

	I = 0;
}

CPU::~CPU()
{

}

void CPU::Process(Memory& mem)
{
	//while (currentInstructionCount > 0)
	{
		Word currentInstruction = (Word)(mem.Data[PC]) << 8;
		currentInstruction |= (Word)(mem.Data[PC + 1]);
		PC += 2;
		
	}
}

void CPU::Render(Memory& mem)
{
	if (timeKeeper.GetTime() < MILLISECONDS_PER_FRAME)
		return;

	if (delayTimer > 0)
		delayTimer--;
	if (soundTimer > 0)
		soundTimer--;


	currentInstructionCount = INSTRUCTIONS_PER_FRAME;
	timeKeeper.Restart();
}