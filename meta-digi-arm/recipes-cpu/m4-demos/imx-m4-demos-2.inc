# Copyright 2017-2018 NXP
# Released under the MIT license (see COPYING.MIT for the terms)

SUMMARY = "i.MX M4 core Demo images"
SECTION = "app"
LICENSE = "Proprietary"

inherit deploy fsl-eula2-unpack2

SOC        ?= "INVALID"
SOC_mx7ulp  = "imx7ulp"
SOC_mx8mm   = "imx8mm"
SOC_mx8mq   = "imx8mq"
SOC_mx8qm   = "imx8qm"
SOC_mx8qxp  = "imx8qx"

IMX_PACKAGE_NAME = "${SOC}-m4-demo-${PV}"
SRC_URI_append = ";name=${SOC}"

SCR = "SCR-${SOC}-m4-demo.txt"

do_deploy () {
   # Install the demo binaries
   cp ${D}/* ${DEPLOYDIR}/
   chmod 0644 ${DEPLOYDIR}/*
}
addtask deploy after do_install

PACKAGE_ARCH = "${MACHINE_SOCARCH}"
