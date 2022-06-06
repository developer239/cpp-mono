function dumpTable(table)
    for key, value in pairs(table) do
        print(key, value)
    end
end

function boundingBoxCenter(boundingBox)
    return {
        x = boundingBox.positionX + boundingBox.width / 2,
        y = boundingBox.positionY + boundingBox.height / 2
    }
end

function calculateDistanceBetweenTwoPoints(pointA, pointB)
    return math.sqrt(math.pow(pointA.x - pointB.x, 2) + math.pow(pointA.y - pointB.y, 2))
end

function playApple()
    ticks = sdl_get_ticks()

    apples = get_entities_by_group("Apple")
    areaPlayer = get_entity_by_tag("AreaPlayer")

    playerAreaBoundingBox = get_entity_bounding_box(areaPlayer)
    playerAreaBoundingBoxCenter = boundingBoxCenter(playerAreaBoundingBox)

    closestAppleIndex = -1
    closestAppleDistance = 999
    closestAppleCenter = { x = 0, y = 0 }

    for i, apple in ipairs(apples) do
        targetAppleBoundingBox = get_entity_bounding_box(apple)
        targetAppleBoundingBoxCenter = boundingBoxCenter(targetAppleBoundingBox)

        targetAppleDistance = calculateDistanceBetweenTwoPoints(playerAreaBoundingBoxCenter, targetAppleBoundingBoxCenter)

        if (targetAppleDistance < closestAppleDistance) then
            closestAppleDistance = targetAppleDistance
            closestAppleIndex = i
            closestAppleCenter = targetAppleBoundingBoxCenter
        end
    end

    if (closestAppleCenter.x > 0 and closestAppleCenter.y > 0) then
        mouse_move(closestAppleCenter.x, closestAppleCenter.y + 60)
    end
end

function onUpdate()
    playApple()
end

Level = {
    window = {
        windowX = 0,
        windowY = 60,
    },
    targets = {
        [0] = {
            tag = "Apple",
            detectColors = {
                lowerRed = 0,
                lowerGreen = 0,
                lowerBlue = 105,
                upperRed = 200,
                upperGreen = 65,
                upperBlue = 255,
                minWidth = 22,
                minHeight = 22
            },
            erodeDilate = {
                width = 10,
                height = 10,
            }
        },
    },
    entities = {
        [0] = {
            tag = "AreaPlayer",
            group = "Area",
            components = {
                boundingBox = {
                    x = 375,
                    y = 275,
                    width = 50,
                    height = 50
                },
            }
        },
    }
}