// MESSAGE MISSION_COUNT PACKING

#define MAVLINK_MSG_ID_MISSION_COUNT 44

typedef struct __mavlink_mission_count_t
{
    uint16_t count; ///< Number of mission items in the sequence
    uint8_t target_system; ///< System ID
    uint8_t target_component; ///< Component ID
} mavlink_mission_count_t;

#define MAVLINK_MSG_ID_MISSION_COUNT_LEN 4
#define MAVLINK_MSG_ID_44_LEN 4



#define MAVLINK_MESSAGE_INFO_MISSION_COUNT { \
	"MISSION_COUNT", \
	3, \
	{  { "count", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_mission_count_t, count) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_mission_count_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_mission_count_t, target_component) }, \
         } \
}


/**
 * @brief Pack a mission_count message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param count Number of mission items in the sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_count_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
        uint8_t target_system, uint8_t target_component, uint16_t count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[4];
    _mav_put_uint16_t(buf, 0, count);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
    mavlink_mission_count_t packet;
    packet.count = count;
    packet.target_system = target_system;
    packet.target_component = target_component;

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_COUNT;
    return mavlink_finalize_message(msg, system_id, component_id, 4, 221);
}

/**
 * @brief Pack a mission_count message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param count Number of mission items in the sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_count_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
        mavlink_message_t* msg,
        uint8_t target_system,uint8_t target_component,uint16_t count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[4];
    _mav_put_uint16_t(buf, 0, count);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
    mavlink_mission_count_t packet;
    packet.count = count;
    packet.target_system = target_system;
    packet.target_component = target_component;

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_COUNT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 4, 221);
}

/**
 * @brief Encode a mission_count struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_count C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_count_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_count_t* mission_count)
{
    return mavlink_msg_mission_count_pack(system_id, component_id, msg, mission_count->target_system, mission_count->target_component, mission_count->count);
}

/**
 * @brief Send a mission_count message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param count Number of mission items in the sequence
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mission_count_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t count)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[4];
    _mav_put_uint16_t(buf, 0, count);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_COUNT, buf, 4, 221);
#else
    mavlink_mission_count_t packet;
    packet.count = count;
    packet.target_system = target_system;
    packet.target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_COUNT, (const char *)&packet, 4, 221);
#endif
}

#endif

// MESSAGE MISSION_COUNT UNPACKING


/**
 * @brief Get field target_system from mission_count message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_mission_count_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field target_component from mission_count message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_mission_count_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field count from mission_count message
 *
 * @return Number of mission items in the sequence
 */
static inline uint16_t mavlink_msg_mission_count_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a mission_count message into a struct
 *
 * @param msg The message to decode
 * @param mission_count C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_count_decode(const mavlink_message_t* msg, mavlink_mission_count_t* mission_count)
{
#if MAVLINK_NEED_BYTE_SWAP
    mission_count->count = mavlink_msg_mission_count_get_count(msg);
    mission_count->target_system = mavlink_msg_mission_count_get_target_system(msg);
    mission_count->target_component = mavlink_msg_mission_count_get_target_component(msg);
#else
    memcpy(mission_count, _MAV_PAYLOAD(msg), 4);
#endif
}
