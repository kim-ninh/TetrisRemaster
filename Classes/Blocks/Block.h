#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <bitset>
#include "cocos2d.h"
#include "define.h"
#include "fstream"
#include "string"

USING_NS_CC;

namespace TetrisGame
{
	
	class Block : public Node
	{
		// Inherited from Cocos Node class
		// init with some default property:

		// scale: 0.5f
		// anchorPoint: (0.f, 0.f)


	public:
		// Block color
		enum COLOR
		{
			BLUE,
			GREEN,
			RED,
			GREY,
			YELLOW
		};

		enum BlockType {
			TBlock,
			LBlock,
			ZBlock,
			OBlock,
			IBlock
		};

	private:
		std::map<COLOR, const char *> color_map = {
			{COLOR::RED, "blocks/red.png"},
			{COLOR::BLUE, "blocks/blue.png"},
			{COLOR::GREY, "blocks/grey.png"},
			{COLOR::GREEN, "blocks/green.png"},
			{COLOR::YELLOW, "blocks/yellow.png"}
		};

	protected:

		// default color:
		COLOR color = COLOR::GREEN;

		// shape is 4 x 4 matrix
		// each member has value 0 and 1
		std::vector<std::vector<short>> shape =
			std::vector<std::vector<short>>(4, std::vector<short>(4, 0));

		std::vector<std::vector<std::vector<char>>> rotateShapes;
		cocos2d::Vec2 bottomLeftPos;

		void loadShapeData(std::string filePath);
	public:
		Block();
		Block(COLOR color);
		void initContentSize();
		//virtual void virtual_Rotate();

		virtual bool init();

		void softFalling();

		void hardFalling();
	};
}

#endif
