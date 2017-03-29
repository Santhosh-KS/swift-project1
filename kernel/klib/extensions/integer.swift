/*
 * kernel/klib/extensions/integer.swift
 *
 * Created by Simon Evans on 28/03/2017.
 * Copyright © 2015 - 2017 Simon Evans. All rights reserved.
 *
 * Extras for UInt8/16/32/64 including initialisers.
 *
 */

extension UInt8 {
    func bit(_ bit: Int) -> Bool {
        return self & (1 << UInt8(bit)) != 0
    }
}


extension UInt16 {
    init(withBytes bytes: [UInt8]) {
        precondition(bytes.count > 0)
        precondition(bytes.count <= Int(UInt16._sizeInBytes))

        self = 0
        var shift: UInt16 = 0
        for byte in bytes {
            self |= (UInt16(byte) << shift)
            shift += 8
        }
    }

    init(withBytes bytes: UInt8...) {
        precondition(bytes.count > 0)
        precondition(bytes.count <= Int(UInt16._sizeInBytes))

        self = 0
        var shift: UInt16 = 0
        for byte in bytes {
            self |= (UInt16(byte) << shift)
            shift += 8
        }
    }

    func bit(_ bit: Int) -> Bool {
        return self & (1 << UInt16(bit)) != 0
    }
}


extension UInt32 {
    init(withBytes bytes: UInt8...) {
        precondition(bytes.count > 0)
        precondition(bytes.count <= Int(UInt32._sizeInBytes))

        self = 0
        var shift: UInt32 = 0
        for byte in bytes {
            self |= (UInt32(byte) << shift)
            shift += 8
        }
    }

    init(withBytes bytes: [UInt8]) {
        precondition(bytes.count > 0)
        precondition(bytes.count <= Int(UInt32._sizeInBytes))

        self = 0
        var shift: UInt32 = 0
        for byte in bytes {
            self |= (UInt32(byte) << shift)
            shift += 8
        }
    }

    func bit(_ bit: Int) -> Bool {
        return self & (1 << UInt32(bit)) != 0
    }
}


extension UInt64 {
    init(withBytes bytes: UInt8...) {
        precondition(bytes.count > 0)
        precondition(bytes.count <= Int(UInt64._sizeInBytes))

        self = 0
        var shift: UInt64 = 0
        for byte in bytes {
            self |= (UInt64(byte) << shift)
            shift += 8
        }
    }

    init(withBytes bytes: [UInt8]) {
        precondition(bytes.count > 0)
        precondition(bytes.count <= Int(UInt64._sizeInBytes))

        self = 0
        var shift: UInt64 = 0
        for byte in bytes {
            self |= (UInt64(byte) << shift)
            shift += 8
        }
    }

    init(withDWords dwords: UInt32...) {
        precondition(dwords.count > 0)
        precondition(dwords.count <= 2)

        self = 0
        var shift: UInt64 = 0
        for dword in dwords {
            self |= (UInt64(dword) << shift)
            shift += 32
        }
    }

    func bit(_ bit: Int) -> Bool {
        return self & (1 << UInt64(bit)) != 0
    }
}