#include "Hud.h"

Hud* Hud::getInstance()
{
	static Hud instance;
	return &instance;
}

ax::LayerColor* Hud::getLayer() const
{
	return _layer;
}

Hud::Hud() :
	_layer(ax::LayerColor::create(ax::Color4B::ORANGE)),
	_logo(ax::ui::ImageView::create("CloseNormal.png"))
{
	//_layer->setAnchorPoint({ 0, 0 });
	_layer->addChild(_logo);
}