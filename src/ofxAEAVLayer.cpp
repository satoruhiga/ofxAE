#include "ofxAEAVLayer.h"
#include "ofGraphics.h"
#include "ofxAEMask.h"

OFX_AE_NAMESPACE_BEGIN

AVLayer::AVLayer()
:is_use_trackmatte_(false)
,trackmatte_layer_(NULL)
{
}

AVLayer::~AVLayer()
{
	for(vector<Mask*>::iterator it = mask_.begin(); it != mask_.end(); ++it) {
		delete *it;
	}
}
void AVLayer::allocate(int width, int height, bool use_mask)
{
	size_.set(width, height);

	if(use_mask) {
		ofx_mask_.setup(width, height);
	}
	is_use_mask_ = use_mask;
}

void AVLayer::draw(float alpha)
{
	getNode().pushMatrix();
	if(is_use_trackmatte_) {
		trackmatte_.beginMask();
	}
	if(is_use_mask_) {
		ofx_mask_.beginMask();
		if(mask_.empty()) {
			ofClear(ofColor::white);
		}
		else {
			vector<Mask*>::iterator it = mask_.begin();
			if((*it)->isSubtract()) {
				ofClear(ofColor::white);
			}
			while(it != mask_.end()) {
				(*it)->draw();
				++it;
			}
		}
		ofx_mask_.endMask();
		ofx_mask_.begin();
		render(alpha);
		ofx_mask_.end();
		ofx_mask_.draw();
	}
	else {
		render(alpha);
	}
	if(is_use_trackmatte_) {
		trackmatte_.endMask();
		trackmatte_.begin();
		trackmatte_layer_->draw(1);
		trackmatte_.end();
		trackmatte_.draw();
	}
	getNode().popMatrix();
}

void AVLayer::addMask(Mask *mask)
{
	mask->setSize(size_);
	mask_.push_back(mask);
	properties_.push_back(&mask->getPath());
	properties_.push_back(&mask->getOpacity());
}

void AVLayer::setTrackMatte(AVLayer *layer)
{
	trackmatte_layer_ = layer;
	trackmatte_.setup(getWidth(), getHeight());
	is_use_trackmatte_ = true;
}

OFX_AE_NAMESPACE_END
/* EOF */