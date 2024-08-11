#pragma once

#include "CommonTypes.h"
#include "NodeStyle.h"

namespace blocki
{
class Node
{
public:
	virtual ~Node() = default;

	static UniquePtr<Node> CreateTextNode(StringView&& content);
	static UniquePtr<Node> CreateElement(NodeStyle&& style);
protected:
	Node() = default;
};

class TextNode : public Node
{
public:
	TextNode(StringView&& content);
private:
	StringView m_TextContent;
};

class Element : public Node
{
public:
	Element(NodeStyle&& style);

	NodeStyle& ModifyStyle();
	const NodeStyle& GetStyle() const;

	void AppendChild(UniquePtr<Node>&& child);
private:
	NodeStyle m_Style;
	Vector<UniquePtr<Node>> m_Children;
};
}