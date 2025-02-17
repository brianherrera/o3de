/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzCore/PlatformDef.h>

#include <AzCore/Memory/SystemAllocator.h>
#include <IGem.h>

#include "AudioSystemGemSystemComponent.h"

namespace AudioSystemGem
{
    class AudioSystemModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(AudioSystemModule, "{BE8CD7ED-AEB9-4617-B069-D848EA986ED3}", CryHooksModule);
        AZ_CLASS_ALLOCATOR(AudioSystemModule, AZ::SystemAllocator);

        AudioSystemModule()
            : CryHooksModule()
        {
            m_descriptors.insert(m_descriptors.end(), {
                AudioSystemGemSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<AudioSystemGemSystemComponent>(),
            };
        }
    };

} // namespace AudioSystemGem

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(Gem_AudioSystem, AudioSystemGem::AudioSystemModule)
