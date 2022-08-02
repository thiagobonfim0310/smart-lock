# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS "main.c" "./DRIVES/rc522/rc522.c" "./APP_NETWORK/APP_Network.c")
set(COMPONENT_ADD_INCLUDEDIRS "." "./DRIVES/rc522/" "./APP_NETWORK")

register_component()
