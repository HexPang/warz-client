// Copyright (c) 2010 NaturalMotion.  All Rights Reserved.
// Not to be copied, adapted, modified, used, distributed, sold,
// licensed or commercially exploited in any manner without the
// written consent of NaturalMotion.
//
// All non public elements of this software are the confidential
// information of NaturalMotion and may not be disclosed to any
// person nor used for any purpose not expressly approved by
// NaturalMotion in writing.

//----------------------------------------------------------------------------------------------------------------------
#ifdef _MSC_VER
  #pragma once
#endif
#ifndef MR_NODE_CHARACTER_CONTROLLER_OVERRIDE_BUILDER_H
#define MR_NODE_CHARACTER_CONTROLLER_OVERRIDE_BUILDER_H
//----------------------------------------------------------------------------------------------------------------------
#include "assetProcessor/NodeBuilder.h"
//----------------------------------------------------------------------------------------------------------------------

namespace AP
{

//----------------------------------------------------------------------------------------------------------------------
/// \class AP::NodeCCOverrideBuilder
/// \brief For construction of NodeCCOverride.
/// \ingroup
//----------------------------------------------------------------------------------------------------------------------
class NodeCCOverrideBuilder : public NodeDefBuilder
{
public:
  virtual bool hasSemanticLookupTable() NM_OVERRIDE;

  virtual MR::SemanticLookupTable* initSemanticLookupTable(
    NMP::Memory::Resource&      memRes) NM_OVERRIDE;

  virtual void getNodeDefInputConnections(
    std::vector<MR::NodeID>&    childNodeIDs,
    const ME::NodeExport*       nodeDefExport,
    const ME::NetworkDefExport* netDefExport,
    AssetProcessor*             processor) NM_OVERRIDE;

  virtual void preInit(
    NetworkDefCompilationInfo*  netDefCompilationInfo,
    const ME::NodeExport*       nodeDefExport,
    const ME::NetworkDefExport* netDefExport,
    AssetProcessor*             processor) NM_OVERRIDE;

  virtual NMP::Memory::Format getNodeDefMemoryRequirements(
    NetworkDefCompilationInfo*  netDefCompilationInfo,
    const ME::NodeExport*       nodeDefExport,
    const ME::NetworkDefExport* netDefExport,
    AssetProcessor*             processor) NM_OVERRIDE;

  virtual MR::NodeDef* init(
    NMP::Memory::Resource&      memRes,
    NetworkDefCompilationInfo*  netDefCompilationInfo,
    const ME::NodeExport*       nodeDefExport,
    const ME::NetworkDefExport* netDefExport,
    AssetProcessor*             processor) NM_OVERRIDE;

private:

  NMP::Memory::Format calculateConditionsMemoryRequirements(
    const ME::DataBlockExport* nodeDefDataBlock,
    AssetProcessor*            processor);
 
  void initConditions(
    NetworkDefCompilationInfo* netDefCompilationInfo,
    MR::NodeDef*               nodeDef,
    const ME::DataBlockExport* nodeDefDataBlock,
    AssetProcessor*            processor,
    NMP::Memory::Resource&     memRe);

  NMP::Memory::Format calculatePropertiesMemoryRequirements(
    const ME::DataBlockExport* nodeDefDataBlock);
  
  void initProperties(
    MR::NodeDef*               nodeDef,
    const ME::DataBlockExport* nodeDefDataBlock,
    NMP::Memory::Resource&     memRes,
    MR::AnimSetIndex           animSetIndex);

  // Initialise as correct NodeDef type; fills in queuing ops table and outputCP ops table.
  void initTaskQueuingFns(
    MR::NodeDef*                nodeDef,
    NetworkDefCompilationInfo*  netDefCompilationInfo,
    NMP::BasicLogger*           logger);
};

} // namespace AP

//----------------------------------------------------------------------------------------------------------------------
#endif // MR_NODE_CHARACTER_CONTROLLER_OVERRIDE_BUILDER_H
//----------------------------------------------------------------------------------------------------------------------