#pragma once

#include "JuceHeader.h"

class ARASampleProjectAudioModification    : public ARAAudioModification
{
public:
    ARASampleProjectAudioModification (ARAAudioSource* audioSource, ARA::ARAAudioModificationHostRef hostRef,
                                       const ARAAudioModification* optionalModificationToClone)
        : ARAAudioModification (audioSource, hostRef, optionalModificationToClone)
    {
        if (auto toClone = static_cast<const ARASampleProjectAudioModification*> (optionalModificationToClone))
            reversePlayback = toClone->reversePlayback;
    }

    bool getReversePlayback() const { return reversePlayback; }
    void setReversePlayback (bool reverse) { reversePlayback = reverse; }

private:
    bool reversePlayback { false };
};
