// MESSAGE RAW_IMU PACKING

#define MAVLINK_MSG_ID_RAW_IMU 28

typedef struct __mavlink_raw_imu_t
{
    uint64_t usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
    int16_t xacc; ///< X acceleration (raw)
    int16_t yacc; ///< Y acceleration (raw)
    int16_t zacc; ///< Z acceleration (raw)
    int16_t xgyro; ///< Angular speed around X axis (raw)
    int16_t ygyro; ///< Angular speed around Y axis (raw)
    int16_t zgyro; ///< Angular speed around Z axis (raw)
    int16_t xmag; ///< X Magnetic field (raw)
    int16_t ymag; ///< Y Magnetic field (raw)
    int16_t zmag; ///< Z Magnetic field (raw)
} mavlink_raw_imu_t;

#define MAVLINK_MSG_ID_RAW_IMU_LEN 26
#define MAVLINK_MSG_ID_28_LEN 26



#define MAVLINK_MESSAGE_INFO_RAW_IMU { \
	"RAW_IMU", \
	10, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_raw_imu_t, usec) }, \
         { "xacc", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_raw_imu_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_raw_imu_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_raw_imu_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_raw_imu_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_raw_imu_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_raw_imu_t, zgyro) }, \
         { "xmag", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_raw_imu_t, xmag) }, \
         { "ymag", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_raw_imu_t, ymag) }, \
         { "zmag", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_raw_imu_t, zmag) }, \
         } \
}


/**
 * @brief Pack a raw_imu message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xacc X acceleration (raw)
 * @param yacc Y acceleration (raw)
 * @param zacc Z acceleration (raw)
 * @param xgyro Angular speed around X axis (raw)
 * @param ygyro Angular speed around Y axis (raw)
 * @param zgyro Angular speed around Z axis (raw)
 * @param xmag X Magnetic field (raw)
 * @param ymag Y Magnetic field (raw)
 * @param zmag Z Magnetic field (raw)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_imu_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
        uint64_t usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[26];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_int16_t(buf, 8, xacc);
    _mav_put_int16_t(buf, 10, yacc);
    _mav_put_int16_t(buf, 12, zacc);
    _mav_put_int16_t(buf, 14, xgyro);
    _mav_put_int16_t(buf, 16, ygyro);
    _mav_put_int16_t(buf, 18, zgyro);
    _mav_put_int16_t(buf, 20, xmag);
    _mav_put_int16_t(buf, 22, ymag);
    _mav_put_int16_t(buf, 24, zmag);

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 26);
#else
    mavlink_raw_imu_t packet;
    packet.usec = usec;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.xmag = xmag;
    packet.ymag = ymag;
    packet.zmag = zmag;

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 26);
#endif

    msg->msgid = MAVLINK_MSG_ID_RAW_IMU;
    return mavlink_finalize_message(msg, system_id, component_id, 26);
}

/**
 * @brief Pack a raw_imu message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xacc X acceleration (raw)
 * @param yacc Y acceleration (raw)
 * @param zacc Z acceleration (raw)
 * @param xgyro Angular speed around X axis (raw)
 * @param ygyro Angular speed around Y axis (raw)
 * @param zgyro Angular speed around Z axis (raw)
 * @param xmag X Magnetic field (raw)
 * @param ymag Y Magnetic field (raw)
 * @param zmag Z Magnetic field (raw)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_imu_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
        mavlink_message_t* msg,
        uint64_t usec,int16_t xacc,int16_t yacc,int16_t zacc,int16_t xgyro,int16_t ygyro,int16_t zgyro,int16_t xmag,int16_t ymag,int16_t zmag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[26];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_int16_t(buf, 8, xacc);
    _mav_put_int16_t(buf, 10, yacc);
    _mav_put_int16_t(buf, 12, zacc);
    _mav_put_int16_t(buf, 14, xgyro);
    _mav_put_int16_t(buf, 16, ygyro);
    _mav_put_int16_t(buf, 18, zgyro);
    _mav_put_int16_t(buf, 20, xmag);
    _mav_put_int16_t(buf, 22, ymag);
    _mav_put_int16_t(buf, 24, zmag);

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 26);
#else
    mavlink_raw_imu_t packet;
    packet.usec = usec;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.xmag = xmag;
    packet.ymag = ymag;
    packet.zmag = zmag;

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 26);
#endif

    msg->msgid = MAVLINK_MSG_ID_RAW_IMU;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 26);
}

/**
 * @brief Encode a raw_imu struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param raw_imu C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_raw_imu_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_raw_imu_t* raw_imu)
{
    return mavlink_msg_raw_imu_pack(system_id, component_id, msg, raw_imu->usec, raw_imu->xacc, raw_imu->yacc, raw_imu->zacc, raw_imu->xgyro, raw_imu->ygyro, raw_imu->zgyro, raw_imu->xmag, raw_imu->ymag, raw_imu->zmag);
}

/**
 * @brief Send a raw_imu message
 * @param chan MAVLink channel to send the message
 *
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xacc X acceleration (raw)
 * @param yacc Y acceleration (raw)
 * @param zacc Z acceleration (raw)
 * @param xgyro Angular speed around X axis (raw)
 * @param ygyro Angular speed around Y axis (raw)
 * @param zgyro Angular speed around Z axis (raw)
 * @param xmag X Magnetic field (raw)
 * @param ymag Y Magnetic field (raw)
 * @param zmag Z Magnetic field (raw)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_raw_imu_send(mavlink_channel_t chan, uint64_t usec, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t xmag, int16_t ymag, int16_t zmag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[26];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_int16_t(buf, 8, xacc);
    _mav_put_int16_t(buf, 10, yacc);
    _mav_put_int16_t(buf, 12, zacc);
    _mav_put_int16_t(buf, 14, xgyro);
    _mav_put_int16_t(buf, 16, ygyro);
    _mav_put_int16_t(buf, 18, zgyro);
    _mav_put_int16_t(buf, 20, xmag);
    _mav_put_int16_t(buf, 22, ymag);
    _mav_put_int16_t(buf, 24, zmag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_IMU, buf, 26);
#else
    mavlink_raw_imu_t packet;
    packet.usec = usec;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;
    packet.xmag = xmag;
    packet.ymag = ymag;
    packet.zmag = zmag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_IMU, (const char *)&packet, 26);
#endif
}

#endif

// MESSAGE RAW_IMU UNPACKING


/**
 * @brief Get field usec from raw_imu message
 *
 * @return Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t mavlink_msg_raw_imu_get_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xacc from raw_imu message
 *
 * @return X acceleration (raw)
 */
static inline int16_t mavlink_msg_raw_imu_get_xacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field yacc from raw_imu message
 *
 * @return Y acceleration (raw)
 */
static inline int16_t mavlink_msg_raw_imu_get_yacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field zacc from raw_imu message
 *
 * @return Z acceleration (raw)
 */
static inline int16_t mavlink_msg_raw_imu_get_zacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field xgyro from raw_imu message
 *
 * @return Angular speed around X axis (raw)
 */
static inline int16_t mavlink_msg_raw_imu_get_xgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field ygyro from raw_imu message
 *
 * @return Angular speed around Y axis (raw)
 */
static inline int16_t mavlink_msg_raw_imu_get_ygyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field zgyro from raw_imu message
 *
 * @return Angular speed around Z axis (raw)
 */
static inline int16_t mavlink_msg_raw_imu_get_zgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field xmag from raw_imu message
 *
 * @return X Magnetic field (raw)
 */
static inline int16_t mavlink_msg_raw_imu_get_xmag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field ymag from raw_imu message
 *
 * @return Y Magnetic field (raw)
 */
static inline int16_t mavlink_msg_raw_imu_get_ymag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field zmag from raw_imu message
 *
 * @return Z Magnetic field (raw)
 */
static inline int16_t mavlink_msg_raw_imu_get_zmag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Decode a raw_imu message into a struct
 *
 * @param msg The message to decode
 * @param raw_imu C-struct to decode the message contents into
 */
static inline void mavlink_msg_raw_imu_decode(const mavlink_message_t* msg, mavlink_raw_imu_t* raw_imu)
{
#if MAVLINK_NEED_BYTE_SWAP
    raw_imu->usec = mavlink_msg_raw_imu_get_usec(msg);
    raw_imu->xacc = mavlink_msg_raw_imu_get_xacc(msg);
    raw_imu->yacc = mavlink_msg_raw_imu_get_yacc(msg);
    raw_imu->zacc = mavlink_msg_raw_imu_get_zacc(msg);
    raw_imu->xgyro = mavlink_msg_raw_imu_get_xgyro(msg);
    raw_imu->ygyro = mavlink_msg_raw_imu_get_ygyro(msg);
    raw_imu->zgyro = mavlink_msg_raw_imu_get_zgyro(msg);
    raw_imu->xmag = mavlink_msg_raw_imu_get_xmag(msg);
    raw_imu->ymag = mavlink_msg_raw_imu_get_ymag(msg);
    raw_imu->zmag = mavlink_msg_raw_imu_get_zmag(msg);
#else
    memcpy(raw_imu, _MAV_PAYLOAD(msg), 26);
#endif
}
