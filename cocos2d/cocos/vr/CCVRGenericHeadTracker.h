/****************************************************************************
 Copyright (c) 2016 Google Inc.
 Copyright (c) 2016-2017 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef CCVRGenericHeadTracker_hpp
#define CCVRGenericHeadTracker_hpp

#include "vr/CCVRProtocol.h"
#include "math/Vec3.h"
#include "math/Mat4.h"

NS_CC_BEGIN

    class CC_DLL VRGenericHeadTracker : public VRIHeadTracker {
    public:
        VRGenericHeadTracker();

        virtual ~VRGenericHeadTracker();

        virtual Vec3 getLocalPosition();

        virtual Mat4 getLocalRotation();

    protected:
        void startTracking();

        void stopTracking();

        Vec3 _localPosition;

        Mat4 _deviceToDisplay;
        Mat4 _worldToInertialReferenceFrame;

        void *_motionMgr;
    };

NS_CC_END

#endif /* CCVRGenericHeadTracker_hpp */
