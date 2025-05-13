import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

CONF_PIN = "pin"
CONF_WANDID = "wand_id"

magiquest_wand_ns = cg.esphome.namespace("magiquest_wand")
MagiquestWand = magiquest_wand_ns.class_("MagiquestWand", cg.Component)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(MagiquestWand),
        cv.Required(CONF_PIN): cv.positive_int,
        cv.Required(CONF_WANDID): cv.positive_int,
    }
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])

    await cg.register_component(var, config)

    cg.add(var.set_pin(config[CONF_PIN]))
    cg.add(var.set_wandid(config[CONF_WANDID]))
    cg.add_library(
        name="RemoteIR",
        repository="https://github.com/Arduino-IRremote/Arduino-IRremote.git",
        version=None,
    )
