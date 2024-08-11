#include "Node.h"

namespace blocki
{
UniquePtr<Node> Node::CreateTextNode(StringView&& content)
{
	return MakeUnique<TextNode>(std::move(content));
}

UniquePtr<Node> Node::CreateElement(NodeStyle&& style)
{
	return MakeUnique<Element>(std::move(style));
}

TextNode::TextNode(StringView&& content)
	: m_TextContent(std::move(content))
{
}

Element::Element(NodeStyle&& style)
	: m_Style(std::move(style))
{
}

NodeStyle& Element::ModifyStyle()
{
	return m_Style;
}

const NodeStyle& Element::GetStyle() const
{
	return m_Style;
}

void Element::AppendChild(UniquePtr<Node>&& child)
{
	m_Children.push_back(std::move(child));
}
}