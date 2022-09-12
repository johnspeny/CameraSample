#include "Hud.h"

Hud* Hud::getInstance()
{
	static Hud instance;
	return &instance;
}

ax::Layer* Hud::getLayer() const
{
	return _layer;
}

Hud::Hud() :
	_layer(ax::Layer::create()),
	_logo(ax::ui::ImageView::create("CloseNormal.png"))
{
	//_layer(ax::LayerColor::create(ax::Color4B::ORANGE)),
	/*_layer->setContentSize(ax::Vec2(ax::Director::getInstance()->getVisibleSize().width, ax::Director::getInstance()->getVisibleSize().height));
	_layer->setIgnoreAnchorPointForPosition(false);
	_layer->setAnchorPoint({ 0.5f, 0.5f });*/
	_layer->addChild(_logo);

	_logo->setPosition(ax::Vec2(50, 50));
}