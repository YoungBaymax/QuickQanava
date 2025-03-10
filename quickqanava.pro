TEMPLATE    =   subdirs
CONFIG      +=  ordered

test-resizer.subdir     = samples/resizer
test-navigable.subdir   = samples/navigable
test-nodes.subdir       = samples/nodes
test-edges.subdir       = samples/edges
test-connector.subdir   = samples/connector
test-groups.subdir      = samples/groups
test-selection.subdir   = samples/selection
test-style.subdir       = samples/style
test-dataflow.subdir    = samples/dataflow
test-topology.subdir    = samples/topology
test-cpp.subdir         = samples/cpp

#SUBDIRS +=  test-resizer
#SUBDIRS +=  test-navigable
SUBDIRS +=  test-nodes
SUBDIRS +=  test-edges
SUBDIRS +=  test-connector
SUBDIRS +=  test-groups
SUBDIRS +=  test-selection
SUBDIRS +=  test-style
SUBDIRS +=  test-topology
SUBDIRS +=  test-dataflow
SUBDIRS +=  test-cpp

OTHER_FILES += ./.travis.yml
