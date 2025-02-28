//
// Copyright 2017 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef PXR_USD_IMAGING_USD_RI_PXR_IMAGING_PXR_BARN_LIGHT_FILTER_ADAPTER_H
#define PXR_USD_IMAGING_USD_RI_PXR_IMAGING_PXR_BARN_LIGHT_FILTER_ADAPTER_H

/// \file usdRiPxrImaging/pxrBarnLightFilterAdapter.h

#include "pxr/pxr.h"
#include "pxr/usdImaging/usdRiPxrImaging/api.h"
#include "pxr/usdImaging/usdImaging/lightFilterAdapter.h"

PXR_NAMESPACE_OPEN_SCOPE


class UsdPrim;

/// \class UsdRiPxrImagingBarnLightFilterAdapter
///
/// Adapter class for lights of type PxrBarnLightFilter
///
class UsdRiPxrImagingBarnLightFilterAdapter : public UsdImagingLightFilterAdapter {
public:
    typedef UsdImagingLightFilterAdapter BaseAdapter;

    UsdRiPxrImagingBarnLightFilterAdapter()
        : UsdImagingLightFilterAdapter()
    {}

    USDRIPXRIMAGING_API
    virtual ~UsdRiPxrImagingBarnLightFilterAdapter();

    USDRIPXRIMAGING_API
    virtual SdfPath Populate(UsdPrim const& prim,
                     UsdImagingIndexProxy* index,
                     UsdImagingInstancerContext const* instancerContext = NULL);

    USDRIPXRIMAGING_API
    virtual bool IsSupported(UsdImagingIndexProxy const* index) const;

protected:
    virtual void _RemovePrim(SdfPath const& cachePath,
                             UsdImagingIndexProxy* index) final;

};


PXR_NAMESPACE_CLOSE_SCOPE

#endif // PXR_USD_IMAGING_USD_RI_PXR_IMAGING_PXR_BARN_LIGHT_FILTER_ADAPTER_H
