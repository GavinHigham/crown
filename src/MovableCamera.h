/*
Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "Types.h"
#include "Camera.h"
#include "Vec2.h"
#include "Mouse.h"
#include "Keyboard.h"

namespace Crown
{

class MovableCamera : public Camera, public MouseListener, public KeyboardListener
{

public:

	//! Constructor
	MovableCamera(const Vec3& position, const Angles& axis, bool visible, float fov, float aspect,
					bool active, float speed, float sensibility);

	//! Destructor
	~MovableCamera();

	//! Returns the camera's mouse movement sensibility
	float GetMouseSensibility() const;

	//! Sets the camera's mouse movement sensibility
	void SetMouseSensibility(float sensibility);

	//! Returns the camera's speed
	float GetSpeed() const;

	//! Sets the camera speed
	void SetSpeed(float speed);

	void SetActive(bool active);

	//! Loads the view matrix
	virtual void Render();

	virtual void KeyPressed(const KeyboardEvent& event);
	virtual void KeyReleased(const KeyboardEvent& event);

protected:

	void MoveForward();
	void MoveBackward();
	void StrafeLeft();
	void StrafeRight();
	void SetViewByMouse();

	Vec2 mRotFactor;
	float mAngleX;
	float mAngleY;

	float mSpeed;
	float mMouseSensibility;

	bool mUpPressed : 1;
	bool mRightPressed : 1;
	bool mDownPressed : 1;
	bool mLeftPressed : 1;
};

} // namespace Crown

