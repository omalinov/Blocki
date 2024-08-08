namespace blocki
{
enum class BlockiDirection
{
	LTR,
	RTL
};

enum class BlockiDisplay
{
	Block,
	Inline,
	InlineBlock,
	ListItem,
	None
	// todo: tables
};

enum class BlockiPosition
{
	Static,
	Relative,
	Absolute,
	Fixed
};

class BlockiLength
{
public:
	enum class Type
	{
		Px,
		Percent,
		Auto
	};

	static BlockiLength CreateAuto();
	static BlockiLength CreatePx(float value);
	static BlockiLength CreatePercent(float value);
private:
	BlockiLength(Type type, float value);

	Type m_Type;
	float m_Value;
};

class BlockiOffsetBox
{
public:
	static BlockiOffsetBox Create(float top, float left, float bottom, float right);

	BlockiOffsetBox() = delete;

	float GetTop() const;
	float GetLeft() const;
	float GetBottom() const;
	float GetRight() const;

	float& ModifyTop();
	float& ModifyLeft();
	float& ModifyBottom();
	float& ModifyRight();
private:
	BlockiOffsetBox(float top, float left, float bottom, float right);

	float m_Top;
	float m_Left;
	float m_Bottom;
	float m_Right;
};

class BlockiNodeInput
{
public:
	BlockiNodeInput();

	const BlockiOffsetBox& GetMargin() const;
	const BlockiOffsetBox& GetBorder() const;
	const BlockiOffsetBox& GetPadding() const;
	const BlockiOffsetBox& GetContent() const;

	BlockiOffsetBox& ModifyMargin();
	BlockiOffsetBox& ModifyBorder();
	BlockiOffsetBox& ModifyPadding();
	BlockiOffsetBox& ModifyContent();
private:
	BlockiOffsetBox m_Margin;
	BlockiOffsetBox m_Border;
	BlockiOffsetBox m_Padding;
	BlockiOffsetBox m_Content;

	BlockiLength m_Top;
	BlockiLength m_Left;
	BlockiLength m_Bottom;
	BlockiLength m_Right;
};
}