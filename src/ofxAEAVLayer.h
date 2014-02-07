#pragma once

#include "ofxAEDef.h"
#include "ofxAELayer.h"
#include "ofxMask.h"

OFX_AE_NAMESPACE_BEGIN

class Mask;
class Marker;

class AVLayer : public Layer {
	friend class Loader;
public:
	AVLayer();
	virtual ~AVLayer();
	void allocate(int width, int height, bool use_mask);
	void draw(float alpha=1);
	float getWidth() { return size_.x; }
	float getHeight() { return size_.y; }
	const ofVec2f& getSize() { return size_; }
	bool is3D() { return is_3d_; }
	bool isCollapse() { return is_collapse_; }
	void addMask(Mask *mask);
	void setTrackMatte(AVLayer *layer);

protected:
	virtual void render(float alpha=1){};
	bool is_3d_;
	bool is_collapse_;
	ofBlendMode blend_mode_;
	ofVec2f size_;
	bool is_use_mask_;
	vector<Mask*> mask_;
	ofxMask ofx_mask_;
	bool is_use_trackmatte_;
	ofxMask trackmatte_;
	AVLayer *trackmatte_layer_;
};

OFX_AE_NAMESPACE_END
/* EOF */